#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::moveUnit(bool isHoldShift)
{
  std::vector<AcuPos> newPos;

  t_bunny_position mousePos = prog.ingamemouse;
  mousePos.x = mousePos.x + cameraPos.x;
  mousePos.y = mousePos.y - 150;
  newPos.emplace_back(mousePos.x, mousePos.y, 0);

  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      if (isHoldShift)
	selectedUnits[i]->addPosToPath(newPos[0]);
      else
	selectedUnits[i]->setNewPath(newPos);
    }
}
