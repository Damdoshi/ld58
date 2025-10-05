#include "inGame.hh"

void ef::InGame::produceUnit(std::shared_ptr<UnitConf> newUnit)
{
  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      if (selectedUnits[i]->getobjType() == PRODUCTOR)
	{
	  std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(selectedUnits[i]);
	  prod->addUnitToQueue(newUnit);
	}
    }
}

