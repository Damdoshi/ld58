#include "object.hh"

ef::Object::Object(std::shared_ptr<ObjectConf>	conf)
  :
  name(conf->name),
  objType(conf->objType),
  pos(300, 350, 0),
  scale(conf->scale),
  rota(0)
{
  img.reset(new Bpixelarray());
  img->Init(conf->img);
}

