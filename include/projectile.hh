#ifndef __PROJECTILE_HH__
#define __PROJECTILE_HH__

#include "object.hh"

namespace ef
{
  enum ProjectileType
    {
     DIRECT,
     ARC,
     RAY
    };

  struct ProjectileConf : public ObjectConf
  {
    ProjectileConf() = default;
    //int LoadConf(std::string &file);
    virtual int LoadConf(Bconf &conf);

    ProjectileType projType;
    double range;
    double speed;
    double rotaSpeed;

    double damage;
    double penetration;
    double radius;
  };

  class Projectile : public Object
  {
  public:
    Projectile() = default;
    Projectile(std::shared_ptr<ProjectileConf> conf);
    void loop();

    ProjectileType getProjType()
    { return projType; };
    int getDamage()
    { return damage; };
    double getPenetration()
    { return penetration; };
    double getRadius()
    { return radius; };
    double getRange()
    { return range; };
    std::shared_ptr<Object> getLockTarget()
    { return lockTarget; };
    AcuPos getDestination()
    { return destination; };

    void setLockTarget(std::shared_ptr<Object> newTarget)
    { lockTarget = newTarget; };
    void setDestination(AcuPos newDestination)
    { destination = newDestination; };

    double rangeMul;

  private:
    double damage;
    double penetration;
    double radius;

    ProjectileType projType;
    double range;
    double speed;
    double rotaSpeed;
    AcuPos destination;
    std::shared_ptr<Object> lockTarget;
  };
}

#endif // __PROJECTILE_HH__
