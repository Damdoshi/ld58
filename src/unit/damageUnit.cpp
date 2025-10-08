#include "Unit.hpp"

void ef::Unit::damageUnit(double damageValue,
			  double penetration)
{
  hp -= damageValue / (1 + (armor - penetration) / 100);
  if (hp < 0)
    hp = 0;
}

