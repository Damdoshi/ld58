#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::updateSelecting()
{
  t_bunny_position mousePos = prog.ingamemouse;
  selectedPos[1] = prog.realmouse;
  selectedPos[1].x = selectedPos[1].x - prog.GetScreen().buffer.width * 0.12;
  selectedPos[1].y = selectedPos[1].y - prog.GetScreen().buffer.height * 0.12;

  selectedPos[1].y = selectedPos[1].y;
  //selectArea.w = (mousePos.x) - selectArea.x;
  //selectArea.h = (mousePos.y) - selectArea.y;
}
