#include "StrategicBoard.hpp"

t_bunny_response      StrategicBoard::ProduceTurret(void)
{
  std::shared_ptr<ef::UnitConf> newUnitConf;
  newUnitConf.reset(new ef::UnitConf());
  std::string unitName = "res/turret.dab";
  newUnitConf->LoadConfFile(unitName);
  ingame.produceUnit(newUnitConf);
  return GO_ON;
}

