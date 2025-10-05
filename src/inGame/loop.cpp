#include "inGame.hh"

void ef::InGame::loop()
{
  // movement & targeting
  for (int i = 0; i < (int)myUnits.size(); i++)
    {
      myUnits[i]->loop(map);
      std::shared_ptr<ProjectileConf> tempProj = myUnits[i]->makeTargeting(enemyUnits);
      if (tempProj.get() != nullptr)
	fireProj(tempProj, true);
    }
  for (int i = 0; i < (int)enemyUnits.size(); i++)
    {
      enemyUnits[i]->loop(map);
      std::shared_ptr<ProjectileConf> tempProj = myUnits[i]->makeTargeting(myUnits);
      if (tempProj.get() != nullptr)
	fireProj(tempProj, false);
    }
  // resolveProj
  for (int i = 0; i < (int)myProj.size(); i++)
    {
      myProj[i]->loop(map);
      if (doProjHit(myProj[i], enemyUnits))
	removeProj(i, true);
    }
  for (int i = 0; i < (int)enemyProj.size(); i++)
    {
      enemyProj[i]->loop(map);
      if (doProjHit(enemyProj[i], myUnits))
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
    for (int j = 0; j < (int)enemyUnits.size(); j++)
      colideUnit(myUnits[i], enemyUnits[j]);
}
