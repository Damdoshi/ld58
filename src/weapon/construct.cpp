#include "weapons.hh"
#include "projectile.hh"

ef::Weapon::Weapon(std::shared_ptr<WeaponConf>	conf)
  :
  Object(conf),
  rangeMul(1),
  isManual(conf->isManual),
  range(conf->range),
  minRange(conf->minRange),
  cooldown(conf->reloadTime),
  reloadTime(conf->reloadTime),
  rotaSpeed(conf->rotaSpeed),
  target(nullptr)
{
  projectile.reset(new ProjectileConf());
  projectile->LoadConfFile(conf->projectile);
}
