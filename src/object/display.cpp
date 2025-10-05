#include "object.hh"
#include <iostream>

void ef::Object::display(std::shared_ptr<Bpixelarray> screen,
			 AcuPos cameraPos)
{
  AcuPos tempPos(pos);
  tempPos.x -= scale.x / 2.0;
  tempPos.y -= scale.y / 2.0;
  tempPos.x += cameraPos.x;
  tempPos.y += cameraPos.y;
  // std::cout << "Object::display : tempPosx " << tempPos.x << " tempPosy " << tempPos.y << " scalex " << scale.x << " scaley " << scale.y << " rota " << rota << std::endl;
  screen->Blit(*img.get(), tempPos, scale, rota);
}
