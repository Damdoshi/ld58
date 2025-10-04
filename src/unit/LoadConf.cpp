#include "Unit.hpp"

int ef::UnitConf::LoadConf(Bconf &conf)
{
  int out = ObjectConf::LoadConf(conf);
  if (out != 1)
    return out;
  char *buf;

  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Weapon.projectile"))
    {
      perror("WeaponConf::LoadConf : failed to get name");
      return -1;
    }
  weapon.clear();
  weapon.insert(0, buf);
  if(!bunny_configuration_getf_double(conf.Get(), &maxHp, "Weapon.range"))
    {
      perror("WeaponConf::LoadConf : failed to get maxHp");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &armor, "Weapon.range"))
    {
      perror("WeaponConf::LoadConf : failed to get armor");
      return -1;
    }
  return 1;
}

