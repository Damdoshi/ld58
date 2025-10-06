#include "inGame.hh"

bool ef::InGame::doProjHit(std::shared_ptr<Projectile> proj,
			   std::vector<std::shared_ptr<Unit>> otherUnit)
{
  //std::cout << "int doProjHit proj->getPos().x " << proj->getPos().x << " y " << proj->getPos().y << std::endl;
  if (proj->getPos().x < 0 || proj->getPos().y < 0 || proj->getPos().x >= map.size.x || proj->getPos().y >= map.size.y)
    return true;
  for (int i = 0; i < (int)otherUnit.size(); i++)
    {
      if (proj->getPos().x > otherUnit[i]->getPos().x - otherUnit[i]->getScale().x &&
	  proj->getPos().x < otherUnit[i]->getPos().x + otherUnit[i]->getScale().x &&
	  proj->getPos().y > otherUnit[i]->getPos().y - otherUnit[i]->getScale().y &&
	  proj->getPos().y < otherUnit[i]->getPos().y + otherUnit[i]->getScale().y)
	{
	  std::cout << "doProjHit damage" << std::endl;
	  otherUnit[i]->damageUnit(proj->getDamage(), proj->getPenetration());
	  return true;
	}
    }
  return false;
}


