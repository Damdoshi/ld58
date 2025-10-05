#ifndef __WEAPONS_HH__
#define __WEAPONS_HH__

#include "object.hh"

namespace ef
{
  struct WeaponConf : public ObjectConf
  {
    WeaponConf() = default;
    //int LoadConf(std::string &file);
    virtual int LoadConf(Bconf &conf);

    bool isManual;
    double range;
    double minRange;
    double reloadTime;
    double rotaSpeed;
    std::string projectile;
  };

  struct ProjectileConf;

  class Weapon : public Object
  {
  public:
    Weapon() = default;
    Weapon(std::shared_ptr<WeaponConf> conf);
    void loop(AcuPos weaponPos,
	      AcuPos unitPos,
	      double unitRota);
    void manualAiming(AcuPos weaponPos,
		      AcuPos unitPos,
		      double unitRota,
		      AcuPos targetPos);
    std::shared_ptr<ProjectileConf> shoot();

    double getRange()
    { return range; };
    double getMinRange()
    { return minRange; };
    std::shared_ptr<ProjectileConf> getProjectile()
    { return projectile; };
    std::shared_ptr<Object> getTarget()
    { return target; };

    void setTarget(std::shared_ptr<Object> newTarget)
    { target = newTarget; };

    double rangeMul;

  private:
    // gameplay
    bool isManual;
    double range;
    double minRange;
    double cooldown;
    double reloadTime;
    double rotaSpeed;

    std::shared_ptr<ProjectileConf> projectile;
    std::shared_ptr<Object> target;
  };
};

#endif // __WEAPONS_HH__
