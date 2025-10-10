#include "inGame.hh"

void ef::InGame::selectUnit(t_bunny_area area)
{
  if (area.w == 0 || area.h == 0)
    return;
  selectedUnits.clear();
  for (int i = 0; i < (int)myUnits.size(); i++)
    {
      if (myUnits[i]->getPos().x > area.x && myUnits[i]->getPos().x < area.x + area.w &&
	  myUnits[i]->getPos().y > area.y && myUnits[i]->getPos().y < area.y + area.h)
	{
	  std::cout << "selectedUnits unit selected" << std::endl;
	  selectedUnits.push_back(myUnits[i]);
	}
    }
}

