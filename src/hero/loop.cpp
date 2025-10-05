#include "hero.hh"

void ef::Hero::loop(Map &map,
		    AcuPos targetPos)
{
  Unit::loop(map);
  AcuPos weaponPos(0, 0, 0);
  getWeapon()->manualAiming(weaponPos, getPos(), getRota(), targetPos);
}

