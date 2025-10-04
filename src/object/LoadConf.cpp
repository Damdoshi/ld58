#include "object.hh"
#include <iostream>

int ef::ObjectConf::LoadConfFile(std::string &file)
{
  Bconf conff(file);

  if(conff())
    for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
  if(conff())
    {
      perror("Object::LoadConf : failed to open conf");
      return -1;
    }
  return LoadConf(conff);
}

int ef::ObjectConf::LoadConf(Bconf &conf)
{
  char *buf;

  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Object.name"))
    {
      perror("Object::LoadConf : failed to get name");
      return -1;
    }
  std::cout << "Object::LoadConf : buf " << buf << std::endl;
  name.clear();
  name.insert(0, buf);
  std::cout << "Object::LoadConf : name " << name << std::endl;
  if(!bunny_configuration_getf_int(conf.Get(), (int *)&objType, "Object.objType"))
    {
      perror("Object::LoadConf : failed to get objType");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &scale.x, "Object.scale.x"))
    {
      perror("Object::LoadConf : failed to get scale.x");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &scale.y, "Object.scale.y"))
    {
      perror("Object::LoadConf : failed to get scale.y");
      return -1;
    }
  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Object.img"))
    {
      perror("Object::LoadConf : failed to get img");
      return -1;
    }
  img.clear();
  img.insert(0, buf);
  return 1;
}
