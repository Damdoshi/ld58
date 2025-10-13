#include "Unit.hpp"

void ef::Unit::display(std::shared_ptr<Bpixelarray> screen,
		       AcuPos cameraPos)
{
  Object::display(screen, cameraPos);
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
}
