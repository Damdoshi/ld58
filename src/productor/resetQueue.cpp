#include "productor.hh"

void ef::Productor::resetQueue()
{
  if ((int)prodQueue.size() > 0 && timeLeftProd != 0)
    {
      resources += (prodQueue[0]->productionTime - timeLeftProd) / prodQueue[0]->productionTime * prodQueue[0]->cost;
      timeLeftProd = 0;
    }
  prodQueue.clear();
}
