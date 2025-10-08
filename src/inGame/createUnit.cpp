#include "inGame.hh"

void ef::InGame::createUnit(std::shared_ptr<UnitConf> conf,
			    bool isMine)
{
  std::shared_ptr<Unit> newUnit;

  newUnit.reset(new Unit(conf));
  if (isMine)
    myUnits.push_back(newUnit);
  else
    enemyUnits.push_back(newUnit);
}
