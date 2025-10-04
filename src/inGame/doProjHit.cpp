#include "inGame.hh"

bool ef::InGame::doProjHit(std::shared_ptr<Projectile> proj,
			   std::vector<std::shared_ptr<Unit>> otherUnit)
{
  for (int i = 0; i < (int)otherUnit.size(); i++)
    if (proj->getPos().x > otherUnit[i]->getPos().x - otherUnit[i]->getScale().x &&
	proj->getPos().x < otherUnit[i]->getPos().x - otherUnit[i]->getScale().x &&
	proj->getPos().y > otherUnit[i]->getPos().y - otherUnit[i]->getScale().y &&
	proj->getPos().y < otherUnit[i]->getPos().y - otherUnit[i]->getScale().y)
      {
	otherUnit[i]->damageUnit(proj->getDamage(), proj->getPenetration());
	return true;
      }
  return false;
}


