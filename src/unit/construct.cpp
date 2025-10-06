#include "Unit.hpp"

ef::Unit::Unit(std::shared_ptr<UnitConf> conf)
  :
  Object(conf),
  MoveModule(conf),
  maxHp(conf->maxHp),
  hp(conf->maxHp),
  armor(conf->armor)
{
  std::shared_ptr<WeaponConf> weaponConf;
  weaponConf.reset(new WeaponConf());
  weaponConf->LoadConfFile(conf->weapon);

  weapon.reset(new Weapon(weaponConf));
}

