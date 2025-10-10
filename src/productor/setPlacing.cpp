#include "productor.hh"

void ef::Productor::setPlacing(bool value)
{
  isPlacing = value;
  if (value)
    isCollecting = !value;
}

