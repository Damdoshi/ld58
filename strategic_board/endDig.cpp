#include "StrategicBoard.hpp"

t_bunny_response StrategicBoard::EndDig(void)
{
  ingame.Mining(false);
  return GO_ON;
}

