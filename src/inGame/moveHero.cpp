#include "inGame.hh"

void ef::InGame::moveHero()
{
  AcuPos movement(hero->getPos());
  if (bunny_get_keyboard()[BKS_Q])
    movement.x -= 100;
  if (bunny_get_keyboard()[BKS_D])
    movement.x += 100;
  if (bunny_get_keyboard()[BKS_Z])
    movement.y -= 100;
  if (bunny_get_keyboard()[BKS_S])
    movement.y += 100;
  std::vector<AcuPos> tempVec;
  tempVec.push_back(movement);
  hero->setNewPath(tempVec);
}


