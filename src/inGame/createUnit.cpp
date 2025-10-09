#include "inGame.hh"

void ef::InGame::createUnit(std::shared_ptr<UnitConf> conf,
			    std::shared_ptr<Unit> creator,
			    bool isMine)
{
  std::shared_ptr<Unit> newUnit;

  std::cout << "ingame createUnit create" << std::endl;
  newUnit.reset(new Unit(conf));
  newUnit->setPos(creator->getPos());
  if (isMine)
    myUnits.push_back(newUnit);
  else
    enemyUnits.push_back(newUnit);
}
