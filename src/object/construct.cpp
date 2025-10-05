#include "object.hh"

ef::Object::Object(std::shared_ptr<ObjectConf>	conf)
  :
  name(conf->name),
  objType(conf->objType),
  pos(300, 350, 0),
  scale(conf->scale),
  rota(0),
  sprite(conf->img != "" ? bunny_load_sprite(conf->img.c_str()) : NULL),
  img(sprite ? std::make_shared<Bpixelarray>(sprite->clipable) : std::make_shared<Bpixelarray>())
{
  // img.reset(sprite);
  // img->Init(conf->img);
}

