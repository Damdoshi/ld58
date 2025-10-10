#include "productor.hh"

void ef::Productor::setCollecting(bool value)
{
  isCollecting = value;
  if (value)
    isPlacing = !value;
}

