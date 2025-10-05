#include "inGame.hh"

void ef::InGame::moveUnit(t_bunny_position pos,
			  bool isHoldShift)
{
  std::vector<AcuPos> newPos;

  newPos.emplace_back(pos.x, pos.y, 0);

  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      if (isHoldShift)
	selectedUnits[i]->addPosToPath(newPos[0]);
      else
	selectedUnits[i]->setNewPath(newPos);
    }
}
