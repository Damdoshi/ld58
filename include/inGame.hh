#ifndef __INGAME_HH__
#define __INGAME_HH__

#include "Map.hpp"
#include "projectile.hh"
#include "Unit.hpp"

namespace ef
{
  class InGame
  {
  public:
    InGame(const std::string &lvl);
    void display(std::shared_ptr<Bpixelarray> screen,
		 bool isInStrategicBoard);
    void loop();

    bool loadLevel(const std::string &lvl);

  private:
    void colideUnit(std::shared_ptr<Unit> currUnit,
		    std::shared_ptr<Unit> otherUnit);
    bool doProjHit(std::shared_ptr<Projectile> proj,
		   std::vector<std::shared_ptr<Unit>> otherUnit);
    void removeProj(int index,
		    bool isMine);

    Map map;
    AcuPos cameraPos;
    std::vector<std::shared_ptr<Unit>>	myUnits;
    std::vector<std::shared_ptr<Unit>>	enemyUnits;
    std::vector<std::shared_ptr<Projectile>>	myProj;
    std::vector<std::shared_ptr<Projectile>>	enemyProj;
  };
};


#endif // __INGAME_HH__
