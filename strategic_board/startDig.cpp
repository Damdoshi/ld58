#include "StrategicBoard.hpp"

t_bunny_response StrategicBoard::StartDig(void)
{
  ingame.Mining(true);
  return GO_ON;
}

