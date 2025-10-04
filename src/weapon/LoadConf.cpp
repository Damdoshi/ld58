#include "weapons.hh"
/*int ef::WeaponConf::LoadConf(std::string &file)
{
  Bconf conff(file);

  if(conff())
    for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
  if(conff())
    {
      perror("WeaponConf::LoadConf : failed to open conf");
      return -1;
    }
  return LoadConf(conff);
  }*/

int ef::WeaponConf::LoadConf(Bconf &conf)
{
  int out = ObjectConf::LoadConf(conf);
  if (out != 1)
    return out;
  char *buf;

  if(!bunny_configuration_getf_double(conf.Get(), &range, "Weapon.range"))
    {
      perror("WeaponConf::LoadConf : failed to get range");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &minRange, "Weapon.range"))
    {
      perror("WeaponConf::LoadConf : failed to get minRange");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &reloadTime, "Weapon.reloadTime"))
    {
      perror("WeaponConf::LoadConf : failed to get reloadTime");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &rotaSpeed, "Weapon.rotaSpeed"))
    {
      perror("WeaponConf::LoadConf : failed to get rotaSpeed");
      return -1;
    }
  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Weapon.projectile"))
    {
      perror("WeaponConf::LoadConf : failed to get name");
      return -1;
    }
  projectile.clear();
  projectile.insert(0, buf);
  return 1;
}
