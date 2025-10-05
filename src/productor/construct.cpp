#include "productor.hh"

ef::Productor::Productor(std::shared_ptr<UnitConf> conf)
  :
  Unit(conf),
  collectCooldown(0),
  isCollecting(false),
  isPlacing(false),
  resources(0),
  timeLeftProd(0)
{
}
