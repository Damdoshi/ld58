#include "Unit.hpp"

void ef::Unit::loop()
{
  AcuPos tempPos(0, 0, 0);
  weapon->loop(tempPos, pos, rota);
}
