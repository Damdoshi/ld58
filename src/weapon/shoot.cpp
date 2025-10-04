#include "weapons.hh"

std::shared_ptr<ef::ProjectileConf> ef::Weapon::shoot()
{
  if (cooldown == 0 && target.get() != nullptr)
    {
      cooldown = reloadTime;
      return projectile;
    }
  return nullptr;
}
