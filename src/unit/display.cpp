#include "Unit.hpp"

void ef::Unit::display(std::shared_ptr<Bpixelarray> screen,
		       AcuPos cameraPos)
{
  Object::display(screen, cameraPos);
  if (team == 1)
    MoveModule::display(getPos(), screen);
  AcuPos tempPos = weapon->getPos();
  AcuPos originPos = weapon->getPos();
  //double originRota = weapon->getRota();
  tempPos.x += pos.x;
  tempPos.y += pos.y;
  weapon->setPos(tempPos);
  //weapon->setRota(originRota + rota);
  weapon->display(screen, cameraPos);
  weapon->setPos(originPos);
  //weapon->setRota(originRota);

  AcuPos posi[2] = {
    {pos.x - 7.5 + cameraPos.x, pos.y - 11 + cameraPos.y, 0},
    {pos.x + 7.5 + cameraPos.x, pos.y - 11 + cameraPos.y, 0}
  };
  screen->setLine(posi[0], posi[1], BLACK);
  posi[1].x = pos.x - 7.5 + 15 * (hp / maxHp);
  screen->setLine(posi[0], posi[1], GREEN);
}
