#include "inGame.hh"

void ef::InGame::loop()
{
  // movement & targeting
  for (int i = 0; i < (int)myUnits.size(); i++)
    {
      myUnits[i]->loop();
      myUnits[i]->makeTargeting(enemyUnits);
    }
  for (int i = 0; i < (int)enemyUnits.size(); i++)
    {
      enemyUnits[i]->loop();
      myUnits[i]->makeTargeting(myUnits);
    }
  //colision
  for (int i = 0; i < (int)myUnits.size(); i++)
    for (int j = 0; j < (int)enemyUnits.size(); j++)
      colideUnit(myUnits[i], enemyUnits[j]);
}
