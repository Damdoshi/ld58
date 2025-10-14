#include "inGame.hh"

void ef::InGame::createUnit(std::shared_ptr<UnitConf> conf,
			    std::shared_ptr<Unit> creator,
			    bool isMine)
{
  std::shared_ptr<Unit> newUnit;

  std::cout << "ingame createUnit create" << std::endl;
  if (conf->objType == PRODUCTOR)
    newUnit.reset(new Productor(conf));
  else
    newUnit.reset(new Unit(conf));
  newUnit->setPos(creator->getPos());
  if (isMine)
    {
      newUnit->setTeam(1);
      myUnits.push_back(newUnit);
    }
  else
    {
      newUnit->setTeam(2);
      enemyUnits.push_back(newUnit);
    }
}
