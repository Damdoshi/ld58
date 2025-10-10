#ifndef __PRODUCTOR_HH__
#define __PRODUCTOR_HH__

#include "Unit.hpp"

namespace ef
{
  class Productor : public Unit
  {
  public:
    Productor() = default;
    Productor(std::shared_ptr<UnitConf> conf);

    void collectResource(Map &map);
    void placeResource(Map &map);
    void setCollecting(bool value);
    void setPlacing(bool value);

    std::shared_ptr<UnitConf> produce();
    void addUnitToQueue(std::shared_ptr<UnitConf> newUnit);
    void resetQueue();
    std::vector<std::shared_ptr<UnitConf>> getQueue()
    { return prodQueue; };
    double getTimeLeftProd()
    { return timeLeftProd; };

  private:
    double collectCooldown;
    double placingCooldown;
    bool isCollecting;
    bool isPlacing;

    double resources;
    double timeLeftProd;
    std::vector<std::shared_ptr<UnitConf>> prodQueue;
  };
};

#endif // __PRODUCTOR_HH__
