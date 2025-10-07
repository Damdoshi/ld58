#include "Unit.hpp"

std::shared_ptr<ef::ProjectileConf> ef::Unit::makeTargeting(std::vector<std::shared_ptr<Unit>> otherUnit)
{
  AcuPos enemyPos;
  double bestDist = 999999999;
  std::shared_ptr<Unit> bestTarget(nullptr);

  for (int i = 0; i < (int)otherUnit.size(); i++)
    {
      enemyPos = otherUnit[i]->getPos();
      double dist = sqrt((pos.x - enemyPos.x) * (pos.x - enemyPos.x) + (pos.y - enemyPos.y) * (pos.y - enemyPos.y));
      if (dist <= weapon->getRange() && dist < bestDist)
	{
	  bestDist = dist;
	  bestTarget = otherUnit[i];
	}
    }
  weapon->setTarget(bestTarget);
  return weapon->shoot();
}

