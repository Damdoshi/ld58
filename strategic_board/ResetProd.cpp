#include "StrategicBoard.hpp"

t_bunny_response      StrategicBoard::ResetProd(void)
{
  ingame.resetUnitProd();
  return GO_ON;
}
