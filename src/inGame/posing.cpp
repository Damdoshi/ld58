#include "inGame.hh"

void ef::InGame::Posing(bool posing)
{
  if ((int)selectedUnits.size() == 0)
    {
      hero->setPlacing(posing);
      return;
    }
  for (int i = 0; i < (int)selectedUnits.size(); i++)
    if (selectedUnits[i]->getobjType() == PRODUCTOR || selectedUnits[i]->getobjType() == HERO)
      {
	std::shared_ptr<Productor> prod = std::static_pointer_cast<Productor>(selectedUnits[i]);
	prod->setPlacing(posing);
      }
}

