#include "Unit.hpp"

void ef::Unit::damageUnit(double damageValue)
{
  hp -= damageValue / (1 + armor / 100);
  if (hp < 0)
    hp = 0;
}

