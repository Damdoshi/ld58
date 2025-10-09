#include "productor.hh"

void ef::Productor::addUnitToQueue(std::shared_ptr<UnitConf> newUnit)
{
  if ((int)prodQueue.size() == 0)
    timeLeftProd = newUnit->productionTime;
  prodQueue.push_back(newUnit);
}
