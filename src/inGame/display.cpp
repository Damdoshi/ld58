#include "inGame.hh"

void ef::InGame::display(std::shared_ptr<Bpixelarray> screen,
			 bool isInStrategicBoard)
{
  if (!isInStrategicBoard)
    {
      // make map display
      map.Display(*screen.get(), cameraPos);
    }
  else
    {
      //display strategic board
    }
}
