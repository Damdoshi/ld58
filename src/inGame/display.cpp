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
      map.Display(*screen.get(), cameraPos);
      if (isSelecting)
	{

	  AcuPos start(selectedPos[0].x, selectedPos[0].y, -1);
	  AcuPos startbis(selectedPos[0].x, selectedPos[1].y, -1);
	  AcuPos end(selectedPos[1].x, selectedPos[1].y, -1);
	  AcuPos endbis(selectedPos[1].x, selectedPos[0].y, -1);
	  //std::cout << "ingame display isSelecting " << isSelecting << std::endl;
	  //std::cout << "ingame display start " << start.x << " " << start.y << std::endl;
	  //std::cout << "ingame display end " << end.x << " " << end.y << std::endl;
	  screen->setLine(endbis, start, GREEN);
	  screen->setLine(start, startbis, GREEN);
	  screen->setLine(startbis, end, GREEN);
	  screen->setLine(end, endbis, GREEN);
	  bunny_set_geometry(&screen->GetClip()->buffer, BGY_LINES, (t_bunny_vertex_array *)&screen->lineVec, NULL);
	  screen->lineVec.length = 0;
	}
	
      //display strategic board
    }
}
