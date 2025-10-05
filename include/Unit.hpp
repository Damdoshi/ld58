// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 12:07:32 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__UNIT_HPP__
# define		__UNIT_HPP__

#include "moveModule.hh"
#include "weapons.hh"

class Map;

namespace ef
{

  struct UnitConf : public ObjectConf, public MoveModuleConf
  {
    UnitConf() = default;
    virtual int LoadConf(Bconf &conf);

    std::string weapon;
    double maxHp;
    double hp;
    double armor;
  };

  class Unit : public Object, public MoveModule
  {
  public:
    //
    Unit(void) = default;
    Unit(std::shared_ptr<UnitConf> conf);
    ~Unit(void);

    void damageUnit(double damageValue,
		    double penetration);
    void loop(Map &map);
    virtual void display(std::shared_ptr<Bpixelarray> screen, AcuPos cameraPos);
    std::shared_ptr<ProjectileConf> makeTargeting(std::vector<std::shared_ptr<Unit>> otherUnit);

    double getMaxHp()
    { return maxHp; };
    double getHp()
    { return hp; };
    double getArmor()
    { return armor; };

  private:

    double maxHp;
    double hp;
    double armor;
    std::shared_ptr<Weapon> weapon;
  };
};

#endif	//		__UNIT_HPP__
