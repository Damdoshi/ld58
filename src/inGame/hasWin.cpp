#include "inGame.hh"

bool ef::InGame::hasWin()
{
  if (hero.get() != nullptr && hero->getHp() > 0 && (int)enemyUnits.size() == 0)
    return true;
  return false;
}


