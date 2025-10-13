#include "StrategicBoard.hpp"

t_bunny_response      StrategicBoard::ProduceTank(void)
{
  std::shared_ptr<ef::UnitConf> newUnitConf;
  newUnitConf.reset(new ef::UnitConf());
  std::string unitName = "res/tank.dab";
  newUnitConf->LoadConfFile(unitName);
  ingame.produceUnit(newUnitConf);
  return GO_ON;
}

