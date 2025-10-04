#ifndef __MOVEMODULE_HH__
#define __MOVEMODULE_HH__

#include "Bconf.hh"
#include "Bpixelarray.hh"
#include <vector>

namespace ef
{
    struct MoveModuleConf
  {
    MoveModuleConf() = default;
    //virtual int LoadConf(std::string &file);
    virtual int LoadConf(Bconf &conf);

    double speed;
    double rotaSpeed;
  };

  class MoveModule
  {
  public:
    MoveModule() = default;
    MoveModule(std::shared_ptr<MoveModuleConf> conf);
    void loop(AcuPos &pos, double &rota);
    void display(AcuPos pos, std::shared_ptr<Bpixelarray> screen);
    void setNewPath(std::vector<AcuPos> newPath)
    { path = newPath; nextPosition = path[path.size() - 1]; };

    double getSpeed()
    { return speed; };
    double getRotaSpeed()
    { return rotaSpeed; };

    void setSpeed(double newSpeed)
    { speed = newSpeed; };
    void setRotaSpeed(double newRotaSpeed)
    { rotaSpeed = newRotaSpeed; };

  private:
    double speed;
    double rotaSpeed;
    AcuPos nextPosition;
    std::vector<AcuPos> path;
  };
};


#endif // __MOVEMODULE_HH__
