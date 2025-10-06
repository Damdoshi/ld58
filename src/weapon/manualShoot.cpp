#include "weapons.hh"

std::shared_ptr<ef::ProjectileConf> ef::Weapon::manualShoot()
{
  if (isManual)
    std::cout << "shoot " << std::endl;
  if (cooldown == 0)
    {
      std::cout << "shoot pass" << std::endl;
      cooldown = reloadTime;
      return projectile;
    }
  return nullptr;
}
