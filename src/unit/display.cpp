#include "Unit.hpp"

void ef::Unit::display(std::shared_ptr<Bpixelarray> screen)
{
  Object::display(screen);
  weapon->display(screen);
}
