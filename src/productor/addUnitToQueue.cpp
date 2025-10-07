#include "productor.hh"

void ef::Productor::addUnitToQueue(std::shared_ptr<UnitConf> newUnit)
{
  prodQueue.push_back(newUnit);
}
