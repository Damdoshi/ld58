#include "projectile.hh"

ef::Projectile::Projectile(std::shared_ptr<ProjectileConf> conf)
  :
  Object(conf),
  damage(conf->damage),
  penetration(conf->penetration),
  radius(conf->radius),
  projType(conf->projType),
  range(conf->range),
  speed(conf->speed),
  rotaSpeed(conf->rotaSpeed),
  destination(-1, -1, -1),
  lockTarget(nullptr)
{}

