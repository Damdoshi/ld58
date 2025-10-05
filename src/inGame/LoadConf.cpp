#include "inGame.hh"

int ef::LvlConf::LoadConfFile(const std::string &file)
{
  Bconf conff(file);

  if(conff())
    for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
  if(conff())
    {
      perror("LvlConf::LoadConf : failed to open conf");
      return -1;
    }
  return LoadConf(conff);
}

int ef::LvlConf::LoadConf(Bconf &conf)
{
  char *buf;

  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "LvlConf.map"))
    {
      perror("LvlConf::LoadConf : failed to get map");
      return -1;
    }
  map.clear();
  map.insert(0, buf);
  if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "LvlConf.hero.unit"))
    {
      perror("LvlConf::LoadConf : failed to get unit");
      return -1;
    }
  hero.unit.clear();
  hero.unit.insert(0, buf);
  if(!bunny_configuration_getf_double(conf.Get(), &hero.startPos.x, "LvlConf.hero.startPos.x"))
    {
      perror("LvlConf::LoadConf : failed to get startPos.x");
      return -1;
    }
  if(!bunny_configuration_getf_double(conf.Get(), &hero.startPos.y, "LvlConf.hero.startPos.y"))
    {
      perror("LvlConf::LoadConf : failed to get startPos.y");
      return -1;
    }

  for (int i = 0; i < bunny_configuration_casesf(conf.Get(), "LvlConf.startingUnit"); i++)
    {
      UnitSetUp tempSetUp;
      if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "LvlConf.startingUnit[%d].unit", i))
	{
	  perror("LvlConf::LoadConf : failed to get unit");
	  return -1;
	}
      tempSetUp.unit.clear();
      tempSetUp.unit.insert(0, buf);
      if(!bunny_configuration_getf_double(conf.Get(), &tempSetUp.startPos.x, "LvlConf.startingUnit[%d].startPos.x", i))
	{
	  perror("LvlConf::LoadConf : failed to get startPos.x");
	  return -1;
	}
      if(!bunny_configuration_getf_double(conf.Get(), &tempSetUp.startPos.y, "LvlConf.startingUnit[%d].startPos.y", i))
	{
	  perror("LvlConf::LoadConf : failed to get startPos.y");
	  return -1;
	}
      startingUnit.push_back(tempSetUp);
    }
  for (int i = 0; i < bunny_configuration_casesf(conf.Get(), "LvlConf.startingEnemy"); i++)
    {
      UnitSetUp tempSetUp;
      if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "LvlConf.startingEnemy[%d].unit", i))
	{
	  perror("LvlConf::LoadConf : failed to get unit");
	  return -1;
	}
      tempSetUp.unit.clear();
      tempSetUp.unit.insert(0, buf);
      if(!bunny_configuration_getf_double(conf.Get(), &tempSetUp.startPos.x, "LvlConf.startingEnemy[%d].startPos.x", i))
	{
	  perror("LvlConf::LoadConf : failed to get startPos.x");
	  return -1;
	}
      if(!bunny_configuration_getf_double(conf.Get(), &tempSetUp.startPos.y, "LvlConf.startingEnemy[%d].startPos.y", i))
	{
	  perror("LvlConf::LoadConf : failed to get startPos.y");
	  return -1;
	}
      startingEnemy.push_back(tempSetUp);
    }
  return 1;
}
