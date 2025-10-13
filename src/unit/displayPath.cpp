#include "Unit.hpp"

void ef::Unit::displayPath(std::shared_ptr<Bpixelarray> screen)
{
  MoveModule::display(getPos(), screen);
}
