#include "inGame.hh"

ef::InGame::InGame(const std::string &lvl,
		   Program &program)
  :
  prog(program),
  map(myUnits, enemyUnits, myProj, enemyProj),
  isSelecting(false)
{
  LvlConf lvlconf;
  lvlconf.LoadConfFile(lvl);
  map.LoadConf(lvlconf.map);
  for (int i = 0; i < (int)lvlconf.startingUnit.size(); i++)
    {
      std::shared_ptr<UnitConf> newUnitConf;
      newUnitConf.reset(new UnitConf());
      newUnitConf->LoadConfFile(lvlconf.startingUnit[i].unit);
      std::shared_ptr<Unit> newUnit;
      if (newUnitConf->objType == PRODUCTOR)
	{
	  std::shared_ptr<Productor> prod;
	  prod.reset(new Productor(newUnitConf));
	  newUnit = prod;
	}
      else if (newUnitConf->objType == UNIT)
	newUnit.reset(new Unit(newUnitConf));
      if (newUnit.get() != nullptr)
	{
	  newUnit->setPos(lvlconf.startingUnit[i].startPos);
	  myUnits.push_back(newUnit);
	}
    }
  for (int i = 0; i < (int)lvlconf.startingEnemy.size(); i++)
    {
      std::shared_ptr<UnitConf> newUnitConf;
      newUnitConf.reset(new UnitConf());
      newUnitConf->LoadConfFile(lvlconf.startingEnemy[i].unit);
      std::shared_ptr<Unit> newUnit;
      if (newUnitConf->objType == PRODUCTOR)
	{
	  std::shared_ptr<Productor> prod;
	  prod.reset(new Productor(newUnitConf));
	  newUnit = prod;
	}
      else if (newUnitConf->objType == UNIT)
	newUnit.reset(new Unit(newUnitConf));
      if (newUnit.get() != nullptr)
	{
	  newUnit->setPos(lvlconf.startingEnemy[i].startPos);
	  enemyUnits.push_back(newUnit);
	}
    }
  std::shared_ptr<UnitConf> newUnitConf;
  newUnitConf.reset(new UnitConf());
  newUnitConf->LoadConfFile(lvlconf.hero.unit);
  std::shared_ptr<Hero> newUnit;
  hero.reset(new Hero(newUnitConf));
  hero->setPos(lvlconf.hero.startPos);
  myUnits.push_back(hero);

  cameraPos.x = 0;
  cameraPos.y = 0;
  cameraPos.w = 320;
  cameraPos.h = 240;
}
