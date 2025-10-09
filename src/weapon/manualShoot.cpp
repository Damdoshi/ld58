#include "weapons.hh"

std::shared_ptr<ef::ProjectileConf> ef::Weapon::manualShoot()
{
  if (cooldown == 0)
    {
      cooldown = reloadTime;
      return projectile;
    }
  return nullptr;
}
