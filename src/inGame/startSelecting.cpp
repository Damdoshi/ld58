#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::startSelecting()
{
  t_bunny_position mousePos = prog.realmouse;
  selectedPos[0] = prog.realmouse;
  selectedPos[0].x = selectedPos[0].x - prog.GetScreen().buffer.width * 0.12;
  selectedPos[0].y = selectedPos[0].y - prog.GetScreen().buffer.height * 0.12;
  selectedPos[1] = prog.realmouse;
  selectedPos[1].x = selectedPos[1].x - prog.GetScreen().buffer.width * 0.12;
  selectedPos[1].y = selectedPos[1].y - prog.GetScreen().buffer.height * 0.12;
  double ratiox = (double)map.size.x / (prog.GetScreen().buffer.width - prog.GetScreen().buffer.width * 0.25);
  double ratioy = (double)map.size.y / (prog.GetScreen().buffer.height - prog.GetScreen().buffer.height * 0.25);
  selectArea.x = (mousePos.x - map.size.x * 0.065) * ratiox;
  selectArea.y = (mousePos.y - map.size.y * 0.065) * ratioy;
  //std::cout << "ingame startSelecting selectArea x " << selectArea.x << " y " << selectArea.y << std::endl;

  isSelecting = true;
}

