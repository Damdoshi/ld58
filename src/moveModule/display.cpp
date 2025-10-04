#include "moveModule.hh"

void ef::MoveModule::display(AcuPos pos,
			     std::shared_ptr<Bpixelarray> screen)
{
  AcuPos start(pos.x, pos.y, -1);
  AcuPos end(nextPosition.x, nextPosition.y, -1);
  screen->setLine(start, end, RED);
  for (int i = 0; i < (int)path.size() - 1; i++)
    {
      start.x = path[i].x;
      start.y = path[i].y;
      end.x = path[i + 1].x;
      end.y = path[i + 1].y;
      screen->setLine(start, end, GREEN);
    }
  //std::cout << "MoveModule::display : length " << screen->lineVec.length << std::endl;
  bunny_set_geometry(&screen->GetClip()->buffer, BGY_LINES, (t_bunny_vertex_array *)&screen->lineVec, NULL);
  screen->lineVec.length = 0;
}

