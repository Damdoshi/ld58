#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include "Bconf.hh"
#include "Bpixelarray.hh"
#include <vector>
#include <memory>
#include <stdio.h>

namespace ef
{
  enum ObjectType
    {
     OBJECT,
     WEAPON,
     UNIT,
     PRODUCTOR
    };

  struct ObjectConf
  {
    ObjectConf() = default;
    int LoadConfFile(std::string &file);
    virtual int LoadConf(Bconf &conf);

    std::string name;
    ObjectType objType;
    AcuPos scale;
    std::string img;
  };

  class ResourceManager;

  class Object
  {
  public:
    Object() = default;
    Object(std::shared_ptr<ObjectConf> conf);
    ~Object(void) { destruct(); }

    virtual void display(std::shared_ptr<Bpixelarray> screen, AcuPos cameraPos);
    void destruct() { if (sprite) bunny_delete_clipable(&sprite->clipable); sprite = NULL; }

    std::string getName()
    { return name; };
    ObjectType getobjType()
    { return objType; };
    AcuPos getPos()
    { return pos; };
    AcuPos getScale()
    { return scale; };
    double getRota()
    { return rota; };

    void setPos(AcuPos newPos)
    { pos = newPos; };
    void setRota(double newRota)
    { rota = newRota; };

  protected:
    std::string name;
    ObjectType objType;

    // gameplay
    std::vector<std::shared_ptr<Object>> isTargeted;

    // display
    AcuPos pos;
    AcuPos scale;
    double rota;
    t_bunny_sprite *sprite;
    std::shared_ptr<Bpixelarray> img;
  };
}

#endif // __OBJECT_HH__
