#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::startSelecting()
{
  t_bunny_position mousePos = prog.ingamemouse;
  selectedPos[0] = mousePos;
  selectedPos[1] = mousePos;
  selectArea.x = mousePos.x + cameraPos.x;
  selectArea.y = mousePos.y - 150;
  isSelecting = true;
}

