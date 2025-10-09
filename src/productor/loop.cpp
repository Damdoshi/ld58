#include "productor.hh"

std::shared_ptr<ef::UnitConf> ef::Productor::produce()
{
  std::shared_ptr<UnitConf> tempConf(nullptr);

  if ((int)prodQueue.size() >= 1)
    {
      std::cout << "Productor produce timeLeftProd " << timeLeftProd << std::endl;
      if (timeLeftProd <= 0)
	{
	  std::cout << "Productor produce hasProduce" << std::endl;
	  std::vector<std::shared_ptr<UnitConf>> tempQueue;
	  for (int i = 1; i < (int)prodQueue.size(); i++)
	    tempQueue.push_back(prodQueue[i]);
	  tempConf = prodQueue[0];
	  /*if ((int)prodQueue.size() == 1)
	    prodQueue.clear();
	    else*/
	    prodQueue = tempQueue;
	  if ((int)prodQueue.size() > 0)
	    timeLeftProd = prodQueue[0]->productionTime;
	  return tempConf;
	}
      double tickCost = 0;
      if (prodQueue[0]->productionTime * prodQueue[0]->cost != 0)
	tickCost = 0.0167 / prodQueue[0]->productionTime * prodQueue[0]->cost;
      if (resources >= tickCost)
	{
	  resources -= tickCost;
	  timeLeftProd -= 0.0167;
	}
    }
  return tempConf;
}
