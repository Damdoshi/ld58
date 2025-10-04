#include "inGame.hh"

void ef::InGame::display(std::shared_ptr<Bpixelarray> screen,
			 bool isInStrategicBoard)
{
  if (!isInStrategicBoard)
    {
      // make map display
      for (int i = 0; i < (int)myUnits.size(); i++)
	myUnits[i]->display(screen, cameraPos);
      for (int i = 0; i < (int)enemyUnits.size(); i++)
	enemyUnits[i]->display(screen, cameraPos);
    }
  else
    {
      //display strategic board
    }
}
