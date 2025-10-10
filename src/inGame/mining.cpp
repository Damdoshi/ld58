#include "inGame.hh"

void ef::InGame::Mining(bool mining)
{
  std::cout << "ingame mining pass" << std::endl;
  for (int i = 0; i < (int)selectedUnits.size(); i++)
    {
      std::cout << "ingame mining objType " << selectedUnits[i]->getobjType() << std::endl;
      if (selectedUnits[i]->getobjType() == PRODUCTOR)
	{
	  std::cout << "ingame mining start collecting" << std::endl;
	  std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(selectedUnits[i]);
	  prod->setCollecting(mining);
	}
    }
}

