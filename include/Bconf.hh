// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:14 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: overload of bunny_configuration from liblapin

#ifndef __BCONF_HH__
#define __BCONF_HH__

#include <lapin.h>
#include <string>
#include <iostream>

namespace ef
{
  class Bconf
  {
  public:
    Bconf(std::string file);
    bool retry(std::string file);
    t_bunny_configuration *Get();
    bool operator() ();
  private:
    t_bunny_configuration *conf;
  };//!Bconf
};

#endif//__BCONF_HH__
