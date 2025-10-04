#include "object.hh"

ef::Object::Object(std::shared_ptr<ObjectConf>	conf)
  :
  name(conf->name),
  objType(conf->objType),
  pos(300, 350, 0),
  scale(conf->scale),
  rota(0),
  sprite(bunny_load_sprite(conf->img.c_str())),
  img(std::make_shared<Bpixelarray>(sprite->clipable))
{
  // img.reset(sprite);
  // img->Init(conf->img);
}

