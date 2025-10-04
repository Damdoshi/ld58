#ifndef __INGAME_HH__
#define __INGAME_HH__

#include "Map.hpp"

namespace ef
{
  class InGame
  {
  public:
    InGame(const std::string &lvl);
    void display(std::shared_ptr<Bpixelarray> screen,
		 bool isInStrategicBoard);
    void loop();
    void colideUnit(std::shared_ptr<Unit> currUnit,
		    std::shared_ptr<Unit> otherUnit);

  private:
    Map map;
    AcuPos cameraPos;
    std::vector<std::shared_ptr<Unit>>	myUnits;
    std::vector<std::shared_ptr<Unit>>	enemyUnits;
  };
};


#endif // __INGAME_HH__
