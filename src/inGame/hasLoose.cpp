#include "inGame.hh"

bool ef::InGame::hasLoose()
{
  if (hero.get() != nullptr && hero->getHp() > 0)
    return false;
  return true;
}


