#include "productor.hh"

void ef::Productor::display(std::shared_ptr<Bpixelarray> screen,
			    AcuPos cameraPos)
{
  Unit::display(screen, cameraPos);

  AcuPos posi[2] = {
    {pos.x - 7.5 + cameraPos.x, pos.y - 12 + cameraPos.y, 0},
    {pos.x + 7.5 + cameraPos.x, pos.y - 12 + cameraPos.y, 0}
  };
  screen->setLine(posi[0], posi[1], BLACK);
  posi[1].x = pos.x - 7.5 + 15 * (resources / maxResources);
  screen->setLine(posi[0], posi[1], PURPLE);
  if ((int)prodQueue.size() > 0)
    {
      posi[0].y = pos.y - 10 + cameraPos.y;
      posi[1].y = pos.y - 10 + cameraPos.y;
      posi[1].x = pos.x + 7.5 + cameraPos.x;
      screen->setLine(posi[0], posi[1], BLACK);
      posi[1].x = pos.x - 7.5 + 15 * (1 - timeLeftProd / prodQueue[0]->productionTime);
      screen->setLine(posi[0], posi[1], WHITE);
    }
}
