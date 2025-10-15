#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::loop()
{
  // movement & targeting & produce
  //std::cout << "ingame loop nbr unit " << (int)myUnits.size() << std::endl;
  //std::cout << "ingame loop nbr enemy " << (int)enemyUnits.size() << std::endl;
  for (int i = 0; i < (int)myUnits.size(); i++)
    {
      myUnits[i]->loop(map);
      std::shared_ptr<ProjectileConf> tempProj;
      //if (!map.Underwater(myUnits[i]->getPos().x, myUnits[i]->getPos().y, myUnits[i]->getPos().z))
      tempProj = myUnits[i]->makeTargeting(enemyUnits);
      if (tempProj.get() != nullptr)
	fireProj(tempProj, true, myUnits[i]);
      if (myUnits[i]->getobjType() == PRODUCTOR || myUnits[i]->getobjType() == HERO)
	{
	  std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(myUnits[i]);
	  std::shared_ptr<UnitConf> tempNewUnit = prod->produce();
	  if (tempNewUnit.get() != nullptr)
	    createUnit(tempNewUnit, myUnits[i], true);
	  prod->collectResource(map);
	  prod->placeResource(map);
	}

    }
  for (int i = 0; i < (int)enemyUnits.size(); i++)
    {
      enemyUnits[i]->loop(map);
      std::shared_ptr<ProjectileConf> tempProj;
      //if (!map.Underwater(enemyUnits[i]->getPos().x, enemyUnits[i]->getPos().y, enemyUnits[i]->getPos().z))
      tempProj = enemyUnits[i]->makeTargeting(myUnits);
      if (tempProj.get() != nullptr)
	fireProj(tempProj, false, enemyUnits[i]);
      if (enemyUnits[i]->getobjType() == PRODUCTOR)
	{
	  std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(enemyUnits[i]);
	  prod->setCollecting(true);
	  if ((int)prod->getQueue().size() == 0)
	    {
	      std::shared_ptr<UnitConf> newConf;
	      newConf.reset(new UnitConf());
	      std::string unitName = "res/soldier.dab";
	      if (waveCount % 20 == 0)
		unitName = "res/tank.dab";
	      newConf->LoadConfFile(unitName);
	      prod->addUnitToQueue(newConf);
	    }
	  std::shared_ptr<UnitConf> tempNewUnit = prod->produce();
	  if (tempNewUnit.get() != nullptr)
	    {
	      createUnit(tempNewUnit, enemyUnits[i], false);
	      waveCount++;
	    }
	  prod->collectResource(map);
	  prod->placeResource(map);
	}
      else if ((enemyUnits[i]->getName() == "Soldier" || enemyUnits[i]->getName() == "Tank") && waveCount > 50)
	{
	  std::vector<AcuPos> path;
	  path.emplace_back(hero->getPos());
	  enemyUnits[i]->setNewPath(path);
	}
    }
  if (waveCount > 50)
    waveCount = 0;
  if (hero.get() != nullptr)
    {
      AcuPos aimingAt(prog.ingamemouse.x, prog.ingamemouse.y - 150, 0);
      hero->loop(map, aimingAt);
    }
  // resolveProj
  for (int i = 0; i < (int)myProj.size(); i++)
    {
      //std::cout << "ingame loop range " << myProj[i]->lifeTime << std::endl;
      bool isBlocked = myProj[i]->loop(map);
      if (doProjHit(myProj[i], enemyUnits) || myProj[i]->lifeTime <= 0 || myProj[i]->getRange() <= 0 || isBlocked)
	removeProj(i, true);
    }
  for (int i = 0; i < (int)enemyProj.size(); i++)
    {
      //std::cout << "ingame loop range " << enemyProj[i]->lifeTime << std::endl;
      bool isBlocked = enemyProj[i]->loop(map);
      if (doProjHit(enemyProj[i], myUnits) || enemyProj[i]->lifeTime <= 0 || enemyProj[i]->getRange() <= 0 || isBlocked)
	removeProj(i, false);
    }

  // kill units
  for (int i = 0; i < (int)myUnits.size(); i++)
    if (myUnits[i]->getHp() <= 0)
      removeUnit(i, true);
  for (int i = 0; i < (int)enemyUnits.size(); i++)
    if (enemyUnits[i]->getHp() <= 0)
      removeUnit(i, false);

  //colision
  
  for (int i = 0; i < (int)myUnits.size(); i++)
      for (int j = 0; j < (int)myUnits.size(); j++)
	{
	  if (i != j && ((myUnits[i]->getobjType() == PRODUCTOR && myUnits[j]->getobjType() == PRODUCTOR) || (myUnits[i]->getobjType() != PRODUCTOR && myUnits[j]->getobjType() != PRODUCTOR)))
	    {
	      AcuPos vec(0, 0, 0);
	      vec = colideUnit(myUnits[i], myUnits[j]);
	      double totalMass = myUnits[i]->getMass() + myUnits[j]->getMass();
	      
	      if (totalMass == 0)
		std::cout << "WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	      double myRatio = 1.0 - myUnits[i]->getMass() / totalMass;
	      double enemyRatio = 1.0 - myUnits[j]->getMass() / totalMass;
	      AcuPos myVec(vec.x * myRatio, vec.y * myRatio, 0);
	      if (myUnits[i]->getPos().x + myVec.x < 0)
		myVec.x = 0;
	      if (myUnits[i]->getPos().y + myVec.y < 0)
		myVec.y = 0;
	      t_bunny_area startArea;
	      startArea.x = myUnits[i]->getPos().x;
	      startArea.y = myUnits[i]->getPos().y;
	      startArea.w = 1;
	      startArea.h = 1;
	      t_bunny_position endArea;
	      endArea.x = myUnits[i]->getPos().x + myVec.x;
	      endArea.y = myUnits[i]->getPos().y + myVec.y;
	      bool canMove = map.IsMoveLegal(startArea, endArea, myUnits[i]->getMaxDivergeance());
	      if (canMove)
		myUnits[i]->setPos(myUnits[i]->getPos() + myVec);
	      AcuPos enemyVec(vec.x * -enemyRatio, vec.y * -enemyRatio, 0);
	      if (myUnits[j]->getPos().x + enemyVec.x < 0)
		enemyVec.x = 0;
	      if (myUnits[j]->getPos().y + enemyVec.y < 0)
		enemyVec.y = 0;
	      startArea.x = myUnits[j]->getPos().x;
	      startArea.y = myUnits[j]->getPos().y;
	      startArea.w = 1;
	      startArea.h = 1;
	      endArea.x = myUnits[j]->getPos().x + enemyVec.x;
	      endArea.y = myUnits[j]->getPos().y + enemyVec.y;
	      canMove = map.IsMoveLegal(startArea, endArea, myUnits[j]->getMaxDivergeance());
	      if (canMove)
		myUnits[j]->setPos(myUnits[j]->getPos() + enemyVec);
	    }
	}
  
    
  for (int i = 0; i < (int)enemyUnits.size(); i++)
      for (int j = 0; j < (int)enemyUnits.size(); j++)
	{
	  if (i != j && ((enemyUnits[i]->getobjType() == PRODUCTOR && enemyUnits[j]->getobjType() == PRODUCTOR) || (enemyUnits[i]->getobjType() != PRODUCTOR && enemyUnits[j]->getobjType() != PRODUCTOR)))
	    {
	      AcuPos vec(0, 0, 0);
	      vec = colideUnit(enemyUnits[i], enemyUnits[j]);
	      double totalMass = enemyUnits[i]->getMass() + enemyUnits[j]->getMass();
	      if (totalMass == 0)
		std::cout << "WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	      double myRatio = 1.0 - enemyUnits[i]->getMass() / totalMass;
	      double enemyRatio = 1.0 - enemyUnits[j]->getMass() / totalMass;
	      AcuPos myVec(vec.x * myRatio, vec.y * myRatio, 0);
	      if (enemyUnits[i]->getPos().x + myVec.x < 0)
		myVec.x = 0;
	      if (enemyUnits[i]->getPos().y + myVec.y < 0)
		myVec.y = 0;
	      t_bunny_area startArea;
	      startArea.x = enemyUnits[i]->getPos().x;
	      startArea.y = enemyUnits[i]->getPos().y;
	      startArea.w = 1;
	      startArea.h = 1;
	      t_bunny_position endArea;
	      endArea.x = enemyUnits[i]->getPos().x + myVec.x;
	      endArea.y = enemyUnits[i]->getPos().y + myVec.y;
	      bool canMove = map.IsMoveLegal(startArea, endArea, enemyUnits[i]->getMaxDivergeance());
	      if (canMove)
		enemyUnits[i]->setPos(enemyUnits[i]->getPos() + myVec);
	      AcuPos enemyVec(vec.x * -enemyRatio, vec.y * -enemyRatio, 0);
	      if (enemyUnits[j]->getPos().x + enemyVec.x < 0)
		enemyVec.x = 0;
	      if (enemyUnits[j]->getPos().y + enemyVec.y < 0)
	        enemyVec.y = 0;
	      startArea.x = enemyUnits[j]->getPos().x;
	      startArea.y = enemyUnits[j]->getPos().y;
	      startArea.w = 1;
	      startArea.h = 1;
	      endArea.x = enemyUnits[j]->getPos().x + enemyVec.x;
	      endArea.y = enemyUnits[j]->getPos().y + enemyVec.y;
	      canMove = map.IsMoveLegal(startArea, endArea, enemyUnits[j]->getMaxDivergeance());
	      if (canMove)
		enemyUnits[j]->setPos(enemyUnits[j]->getPos() + enemyVec);
	    }
	}
  
  for (int i = 0; i < (int)myUnits.size(); i++)
      for (int j = 0; j < (int)enemyUnits.size(); j++)
	{
	  AcuPos vec(0, 0, 0);
	  vec = colideUnit(myUnits[i], enemyUnits[j]);
	  double totalMass = myUnits[i]->getMass() + enemyUnits[j]->getMass();
	  if (totalMass == 0)
	    std::cout << "WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	  double myRatio = 1.0 - myUnits[i]->getMass() / totalMass;
	  double enemyRatio = 1.0 - enemyUnits[j]->getMass() / totalMass;
	  AcuPos myVec(vec.x * myRatio, vec.y * myRatio, 0);
	  if (myUnits[i]->getPos().x + myVec.x < 0)
	    myVec.x = 0;
	  if (myUnits[i]->getPos().y + myVec.y < 0)
	    myVec.y = 0;
	  t_bunny_area startArea;
	  startArea.x = myUnits[i]->getPos().x;
	  startArea.y = myUnits[i]->getPos().y;
	  startArea.w = 1;
	  startArea.h = 1;
	  t_bunny_position endArea;
	  endArea.x = myUnits[i]->getPos().x + myVec.x;
	  endArea.y = myUnits[i]->getPos().y + myVec.y;
	  bool canMove = map.IsMoveLegal(startArea, endArea, myUnits[i]->getMaxDivergeance());
	  if (canMove)
	    myUnits[i]->setPos(myUnits[i]->getPos() + myVec);
	  AcuPos enemyVec(vec.x * -enemyRatio, vec.y * -enemyRatio, 0);
	  if (enemyUnits[j]->getPos().x + enemyVec.x < 0)
	    enemyVec.x = 0;
	  if (enemyUnits[j]->getPos().y + enemyVec.y < 0)
	    enemyVec.y = 0;
	  startArea.x = enemyUnits[j]->getPos().x;
	  startArea.y = enemyUnits[j]->getPos().y;
	  startArea.w = 1;
	  startArea.h = 1;
	  endArea.x = enemyUnits[j]->getPos().x + enemyVec.x;
	  endArea.y = enemyUnits[j]->getPos().y + enemyVec.y;
	  canMove = map.IsMoveLegal(startArea, endArea, enemyUnits[j]->getMaxDivergeance());
	  if (canMove)
	    enemyUnits[j]->setPos(enemyUnits[j]->getPos() + enemyVec);
	}
  
}
