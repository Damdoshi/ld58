#include "projectile.hh"

ef::Projectile::Projectile(std::shared_ptr<ProjectileConf> conf)
  :
  Object(conf),
  rangeMul(1),
  lifeTime(500),
  damage(conf->damage),
  penetration(conf->penetration),
  radius(conf->radius),
  explosionRadius(conf->explosionRadius),
  projType(conf->projType),
  range(conf->range),
  speed(conf->speed),
  rotaSpeed(conf->rotaSpeed),
  destination(-1, -1, -1),
  distToGo(0),
  currDistToGo(0),
  lockTarget(nullptr)
{}

