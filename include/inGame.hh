#ifndef __INGAME_HH__
#define __INGAME_HH__

#include "Map.hpp"
#include "projectile.hh"
#include "productor.hh"

class Warfield;
class StrategicBoard;
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

    void selectUnit(t_bunny_area area);
    void moveUnit(t_bunny_position pos,
		  bool isHoldShift);
    void produceUnit(std::shared_ptr<UnitConf> unitName);
    void resetUnitProd();
    void fireGun();

    friend Warfield;
    friend StrategicBoard;

  private:
    AcuPos colideUnit(std::shared_ptr<Unit> currUnit,
		      std::shared_ptr<Unit> otherUnit);
    bool doProjHit(std::shared_ptr<Projectile> proj,
		   std::vector<std::shared_ptr<Unit>> otherUnit);
    void removeProj(int index,
		    bool isMine);
    void removeUnit(int index,
		    bool isMine);
    void fireProj(std::shared_ptr<ProjectileConf> conf,
		  bool isMine);

    Map map;
    t_bunny_area cameraPos;
    std::vector<std::shared_ptr<Unit>>	myUnits;
    std::vector<std::shared_ptr<Unit>>	selectedUnits;
    std::vector<std::shared_ptr<Unit>>	enemyUnits;
    std::vector<std::shared_ptr<Projectile>>	myProj;
    std::vector<std::shared_ptr<Projectile>>	enemyProj;

  };
};


#endif // __INGAME_HH__
