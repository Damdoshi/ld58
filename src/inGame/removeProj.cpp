#include "inGame.hh"

void ef::InGame::removeProj(int index,
			    bool isMine)
{
  std::vector<std::shared_ptr<Projectile>> tempProjList;

  //std::cout << "removeProj boom" << std::endl;
  if (isMine)
    {
      for (int i = 0; i < (int)myProj.size(); i++)
	{
	  if (i != index)
	    tempProjList.push_back(myProj[i]);
	  else
	    {
	      t_bunny_position posi;
	      posi.x = myProj[i]->getPos().x;
	      posi.y = myProj[i]->getPos().y;
	      if (myProj[i]->getProjType() == ARC)
		map.Hit(posi, myProj[i]->getExplosionRadius(), myProj[i]->getExplosionRadius() / 10.0, true);
	      for (int j = 0; j < (int)enemyUnits.size(); j++)
		if (myProj[i]->getPos().x > enemyUnits[j]->getPos().x - myProj[i]->getExplosionRadius() &&
		    myProj[i]->getPos().x < enemyUnits[j]->getPos().x + myProj[i]->getExplosionRadius() &&
		    myProj[i]->getPos().y > enemyUnits[j]->getPos().y - myProj[i]->getExplosionRadius() &&
		    myProj[i]->getPos().y < enemyUnits[j]->getPos().y + myProj[i]->getExplosionRadius())
		  enemyUnits[j]->damageUnit(myProj[i]->getDamage(), myProj[i]->getPenetration());
	    }
	}
      myProj = tempProjList;
    }
  else
    {
      for (int i = 0; i < (int)enemyProj.size(); i++)
	{
	  if (i != index)
	    tempProjList.push_back(enemyProj[i]);
	  else
	    {
	      t_bunny_position posi;
	      posi.x = enemyProj[i]->getPos().x;
	      posi.y = enemyProj[i]->getPos().y;
	      if (enemyProj[i]->getProjType() == ARC)
		map.Hit(posi, enemyProj[i]->getExplosionRadius(), enemyProj[i]->getExplosionRadius() / 10.0, true);
	      for (int j = 0; j < (int)myUnits.size(); j++)
		if (enemyProj[i]->getPos().x > myUnits[j]->getPos().x - enemyProj[i]->getExplosionRadius() &&
		    enemyProj[i]->getPos().x < myUnits[j]->getPos().x + enemyProj[i]->getExplosionRadius() &&
		    enemyProj[i]->getPos().y > myUnits[j]->getPos().y - enemyProj[i]->getExplosionRadius() &&
		    enemyProj[i]->getPos().y < myUnits[j]->getPos().y + enemyProj[i]->getExplosionRadius())
		  myUnits[j]->damageUnit(enemyProj[i]->getDamage(), enemyProj[i]->getPenetration());
	    }
	}
      enemyProj = tempProjList;
    }
}

