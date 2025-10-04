#include "inGame.hh"

void ef::InGame::display(std::shared_ptr<Bpixelarray> screen,
			 bool isInStrategicBoard)
{
  if (!isInStrategicBoard)
    {
      // make map display
      map.Display(*screen.get(), cameraPos);
      bunny_set_geometry(&screen->GetClip()->buffer, BGY_LINES, (t_bunny_vertex_array *)&screen->lineVec, NULL);
      screen->lineVec.length = 0;
      for (int i = 0; i < (int)myUnits.size(); i++)
	myUnits[i]->display(screen, ef::AcuPos{cameraPos.x, cameraPos.y, 0});
      for (int i = 0; i < (int)enemyUnits.size(); i++)
	enemyUnits[i]->display(screen, ef::AcuPos{cameraPos.x, cameraPos.y, 0});
    }
  else
    {
      //display strategic board
    }
}
