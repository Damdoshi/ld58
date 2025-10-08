#include "inGame.hh"

void ef::InGame::removeUnit(int index,
			    bool isMine)
{
  std::vector<std::shared_ptr<Unit>> tempUnitList;

  if (isMine)
    {
      for (int i = 0; i < (int)myUnits.size(); i++)
	if (i != index)
	  tempUnitList.push_back(myUnits[i]);
      myUnits = tempUnitList;
    }
  else
    {
      for (int i = 0; i < (int)enemyUnits.size(); i++)
	if (i != index)
	  tempUnitList.push_back(enemyUnits[i]);
      enemyUnits = tempUnitList;
    }
}

