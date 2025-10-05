#ifndef __HERO_HH__
#define __HERO_HH__

#include "productor.hh"

namespace ef
{
  class Hero : public Productor
  {
  public:
    Hero() = default;
    Hero(std::shared_ptr<UnitConf> conf);

    void loop(Map &map,
	      AcuPos targetPos);
    std::shared_ptr<ProjectileConf> shoot()
    { return getWeapon()->shoot(); };

  private:
    
  };
};

#endif // __HERO_HH__
