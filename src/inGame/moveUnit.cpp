#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::moveUnit(bool isHoldShift)
{
  std::vector<AcuPos> newPos;

  t_bunny_position mousePos = prog.realmouse;
  double ratiox = (double)map.size.x / (prog.GetScreen().buffer.width - prog.GetScreen().buffer.width * 0.25);
  double ratioy = (double)map.size.y / (prog.GetScreen().buffer.height - prog.GetScreen().buffer.height * 0.25);
  mousePos.x = (mousePos.x - map.size.x * 0.065) * ratiox;
  mousePos.y = (mousePos.y - map.size.y * 0.065) * ratioy;
  std::cout << "ingame mousePos mousePos " << mousePos.x << " " << mousePos.y << std::endl;
  newPos.emplace_back(mousePos.x, mousePos.y, 0);
  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      if (isHoldShift)
	selectedUnits[i]->addPosToPath(newPos[0]);
      else
	selectedUnits[i]->setNewPath(newPos);
    }
}
