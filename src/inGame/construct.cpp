#include "inGame.hh"

ef::InGame::InGame(const std::string &lvl)
  :
  map(myUnits, enemyUnits, myProj, enemyProj)
{
  map.LoadConf(lvl);
  cameraPos.x = 10;
  cameraPos.y = 10;
  cameraPos.w = 320;
  cameraPos.h = 240;
}
