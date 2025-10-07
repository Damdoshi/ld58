#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::endSelecting()
{
  t_bunny_position mousePos = prog.ingamemouse;
  selectedPos[1] = mousePos;
  selectArea.w = (mousePos.x + cameraPos.x) - selectArea.x;
  selectArea.h = (mousePos.y - 150) - selectArea.y;
  isSelecting = false;
  selectUnit(selectArea);
}

