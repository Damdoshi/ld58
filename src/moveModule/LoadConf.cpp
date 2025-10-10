#include "moveModule.hh"
/*
int ef::MoveModuleConf::LoadConf(std::string &file)
{
  Bconf conff(file);

  if(conff())
    for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
  if(conff())
    {
      perror("MoveModuleConf::LoadConf : failed to open conf");
      return -1;
    }
  return LoadConf(conff);
}
*/
int ef::MoveModuleConf::LoadConf(Bconf &conf)
{
  std::cout << "movemoduleconf pass" << std::endl;
  if(!bunny_configuration_getf_double(conf.Get(), &speed, "MoveModule.speed"))
    {
      perror("MoveModuleConf::LoadConf : failed to get speed");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &rotaSpeed, "MoveModule.rotaSpeed"))
    {
      perror("MoveModuleConf::LoadConf : failed to get rotaSpeed");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &maxDivergeance, "MoveModule.maxDivergeance"))
    {
      perror("MoveModuleConf::LoadConf : failed to get maxDivergeance");
      return -1;
    }
  return 1;
}
