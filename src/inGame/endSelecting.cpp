#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::endSelecting()
{
  t_bunny_position mousePos = prog.realmouse;
  selectedPos[1] = prog.realmouse;
  selectedPos[1].x = selectedPos[1].x - prog.GetScreen().buffer.width * 0.12;
  selectedPos[1].y = selectedPos[1].y - prog.GetScreen().buffer.height * 0.12;

  //std::cout << "ingame endSelecting screensize " << prog.GetScreen().buffer.width << " " << prog.GetScreen().buffer.height << std::endl;
  //std::cout << "ingame endSelecting mapSize " << map.size.x << " " << map.size.y << std::endl;

  double ratiox = (double)map.size.x / (prog.GetScreen().buffer.width - prog.GetScreen().buffer.width * 0.25);
  double ratioy = (double)map.size.y / (prog.GetScreen().buffer.height - prog.GetScreen().buffer.height * 0.25);
  selectArea.w = ((mousePos.x - map.size.x * 0.065) * ratiox - selectArea.x);
  selectArea.h = ((mousePos.y - map.size.y * 0.065) * ratioy - selectArea.y);
  isSelecting = false;

  //std::cout << "ingame endSelecting selectArea x " << selectArea.x << " y " << selectArea.y << std::endl;
  //std::cout << "ingame endSelecting selectArea w " << selectArea.w << " h " << selectArea.h << std::endl;
  selectUnit(selectArea);
}

