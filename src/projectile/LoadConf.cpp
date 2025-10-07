#include "projectile.hh"
/*
int ef::ProjectileConf::LoadConf(std::string &file)
{
  Bconf conff(file);

  if(conff())
    for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
  if(conff())
    {
      perror("ProjectileConf::LoadConf : failed to open conf");
      return -1;
    }
  return LoadConf(conff);
}
*/
int ef::ProjectileConf::LoadConf(Bconf &conf)
{
  int out = ObjectConf::LoadConf(conf);
  if (out != 1)
    return out;
  if(!bunny_configuration_getf_int(conf.Get(), (int *)&projType, "Projectile.projType"))
    {
      perror("ProjectileConf::LoadConf : failed to get projType");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &range, "Projectile.range"))
    {
      perror("ProjectileConf::LoadConf : failed to get range");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &speed, "Projectile.speed"))
    {
      perror("ProjectileConf::LoadConf : failed to get speed");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &rotaSpeed, "Projectile.rotaSpeed"))
    {
      perror("ProjectileConf::LoadConf : failed to get rotaSpeed");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &damage, "Projectile.damage"))
    {
      perror("ProjectileConf::LoadConf : failed to get damage");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &penetration, "Projectile.penetration"))
    {
      perror("ProjectileConf::LoadConf : failed to get penetration");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &radius, "Projectile.radius"))
    {
      perror("ProjectileConf::LoadConf : failed to get radius");
      return -1;
    }
  return 1;
}
