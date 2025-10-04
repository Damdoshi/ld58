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
    void damageUnit(double damageValue);
    void loop();
    virtual void display(std::shared_ptr<Bpixelarray> screen);

  private:
    double maxHp;
    double hp;
    double armor;
    std::shared_ptr<Weapon> weapon;
  };
};

#endif	//		__UNIT_HPP__
