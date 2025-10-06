#include "Unit.hpp"

void ef::Unit::display(std::shared_ptr<Bpixelarray> screen,
		       AcuPos cameraPos)
{
  Object::display(screen, cameraPos);
  MoveModule::display(getPos(), screen);
  weapon->display(screen, cameraPos);
}
