#include "object.hh"
#include <iostream>

void ef::Object::display(std::shared_ptr<Bpixelarray> screen,
			 AcuPos cameraPos)
{
  AcuPos tempPos(pos);
  AcuPos siz{scale.x * img.get()->GetClipSize().x, scale.y * img.get()->GetClipSize().y};

  tempPos.x -= siz.x / 2.0;
  tempPos.y -= siz.y / 2.0;
  tempPos.x += cameraPos.x;
  tempPos.y += cameraPos.y;
  // std::cout << "Object::display : tempPosx " << tempPos.x << " tempPosy " << tempPos.y << " scalex " << scale.x << " scaley " << scale.y << " rota " << rota << std::endl;
  if (img.get())
    screen->Blit(*img.get(), tempPos, siz, rota);
}
