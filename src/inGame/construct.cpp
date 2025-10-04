#include "inGame.hh"

ef::InGame::InGame(const std::string &lvl)
  :
  map()
{
  map.LoadConf(lvl);
}
