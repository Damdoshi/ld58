#include "inGame.hh"

ef::InGame::InGame(const std::string &lvl)
  :
  map(myUnits, enemyUnits, myProj, enemyProj)
{
  map.LoadConf(lvl);
  cameraPos.x = 0;
  cameraPos.y = 0;
  cameraPos.w = 320;
  cameraPos.h = 240;
}
