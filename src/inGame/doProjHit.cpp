#include "inGame.hh"

bool ef::InGame::doProjHit(std::shared_ptr<Projectile> proj,
			   std::vector<std::shared_ptr<Unit>> otherUnit)
{
  //std::cout << "int doProjHit proj->getPos().x " << proj->getPos().x << " y " << proj->getPos().y << std::endl;
  if (proj->getPos().x < 0 || proj->getPos().y < 0 || proj->getPos().x >= map.size.x || proj->getPos().y >= map.size.y)
    return true;
  for (int i = 0; i < (int)otherUnit.size(); i++)
    {
      if (proj->getPos().x > otherUnit[i]->getPos().x - proj->getRadius() &&
	  proj->getPos().x < otherUnit[i]->getPos().x + proj->getRadius() &&
	  proj->getPos().y > otherUnit[i]->getPos().y - proj->getRadius() &&
	  proj->getPos().y < otherUnit[i]->getPos().y + proj->getRadius() &&
	  proj->getPos().z > otherUnit[i]->getPos().z - proj->getRadius() &&
	  proj->getPos().z < otherUnit[i]->getPos().z + proj->getRadius())
	{
	  //std::cout << "doProjHit damage" << std::endl;
	  for (int j = 0; j < (int)otherUnit.size(); j++)
	    if (proj->getPos().x > otherUnit[j]->getPos().x - proj->getExplosionRadius() &&
		proj->getPos().x < otherUnit[j]->getPos().x + proj->getExplosionRadius() &&
		proj->getPos().y > otherUnit[j]->getPos().y - proj->getExplosionRadius() &&
		proj->getPos().y < otherUnit[j]->getPos().y + proj->getExplosionRadius())
	      otherUnit[j]->damageUnit(proj->getDamage(), proj->getPenetration());
	  return true;
	}
    }
  return false;
}


