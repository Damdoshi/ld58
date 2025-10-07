#ifndef __INGAME_HH__
#define __INGAME_HH__

#include "Map.hpp"
#include "projectile.hh"
#include "hero.hh"

class Warfield;
class StrategicBoard;
class Program;
namespace ef
{
  struct UnitSetUp
  {
    std::string unit;
    AcuPos startPos;
  };

  struct LvlConf
  {
    int LoadConfFile(const std::string &file);
    int LoadConf(Bconf &conf);

    std::string map;
    std::vector<UnitSetUp> startingUnit;
    std::vector<UnitSetUp> startingEnemy;
    UnitSetUp hero;
  };

  class InGame
  {
  public:
    InGame(const std::string &lvl, Program &newProg);
    void display(std::shared_ptr<Bpixelarray> screen,
		 bool isInStrategicBoard);
    void loop();

    bool loadLevel(const std::string &lvl);

    void selectUnit(t_bunny_area area);
    void moveUnit(bool isHoldShift);
    void produceUnit(std::shared_ptr<UnitConf> unitName);
    void resetUnitProd();
    void fireGun();
    void moveHero();
    bool spawn(t_bunny_position		pos,
	       const std::string	&type);
    void startSelecting();
    void endSelecting();
    void updateSelecting();

    friend Warfield;
    friend StrategicBoard;

  private:
  public:
    AcuPos colideUnit(std::shared_ptr<Unit> currUnit,
		      std::shared_ptr<Unit> otherUnit);
    bool doProjHit(std::shared_ptr<Projectile> proj,
		   std::vector<std::shared_ptr<Unit>> otherUnit);
    void removeProj(int index,
		    bool isMine);
    void removeUnit(int index,
		    bool isMine);
    void fireProj(std::shared_ptr<ProjectileConf> conf,
		  bool isMine,
		  std::shared_ptr<Unit> unit);
    void createUnit(std::shared_ptr<UnitConf> conf,
		    bool isMine);

    Program &prog;
    Map map;
    t_bunny_area cameraPos;
    t_bunny_area selectArea;
    t_bunny_position selectedPos[2];
    bool isSelecting;
    std::vector<std::shared_ptr<Unit>>	myUnits;
    std::vector<std::shared_ptr<Unit>>	selectedUnits;
    std::vector<std::shared_ptr<Unit>>	enemyUnits;
    std::vector<std::shared_ptr<Projectile>>	myProj;
    std::vector<std::shared_ptr<Projectile>>	enemyProj;
    std::shared_ptr<Hero> hero;
  };
};


#endif // __INGAME_HH__
