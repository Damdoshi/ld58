#include "inGame.hh"

void ef::InGame::resetUnitProd()
{
  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      if (selectedUnits[i]->getobjType() == PRODUCTOR)
	{
	  std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(selectedUnits[i]);
	  prod->resetQueue();
	}
    }
}


