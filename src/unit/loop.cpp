#include "Unit.hpp"
#include "Map.hpp"

void ef::Unit::loop(Map &map)
{
  AcuPos tempPos(0, 0, 0);
  MoveModule::loop(pos, rota, map, scale);
  weapon->loop(tempPos, pos, rota);
}
