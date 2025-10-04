#include "projectile.hh"

void ef::Projectile::loop()
{
  if (lockTarget.get() != nullptr)
    {
      // check rotation
      AcuPos tempPos(cos(getRota()) * speed, sin(getRota()) * speed, 0);
      AcuPos tempPos3(cos(getRota() + M_PI / 2) * speed, sin(getRota() + M_PI / 2) * speed, 0);
      AcuPos tempPos2(lockTarget->getPos().x - getPos().x, lockTarget->getPos().y - getPos().y, 0);
      double dist1 = tempPos.x * tempPos.x + tempPos.y * tempPos.y;
      double dist2 = tempPos2.x * tempPos2.x + tempPos2.y * tempPos2.y;
      double angle = (tempPos.x * tempPos2.x + tempPos.y * tempPos2.y) / sqrt(dist1 * dist2);

      if (angle > rotaSpeed)
	setRota(getRota() - rotaSpeed);
      else if (angle < -rotaSpeed)
	setRota(getRota() + rotaSpeed);
      else
	setRota(getRota() - angle);

      // movement
      if (range > 0)
	{
	  AcuPos oldPos = pos;
	  //std::cout << "projectile::loop : posx " << pos.x + tempPos3.x << " posy " << pos.y + tempPos3.y << " targetx " << lockTarget->getPos().x << " targety " << lockTarget->getPos().y << std::endl;
	  if (pos.x + tempPos3.x < lockTarget->getPos().x + lockTarget->getScale().x / 2 &&
	      pos.x + tempPos3.x > lockTarget->getPos().x - lockTarget->getScale().x / 2 &&
	      pos.y + tempPos3.y < lockTarget->getPos().y + lockTarget->getScale().y / 2 &&
	      pos.y + tempPos3.y > lockTarget->getPos().y - lockTarget->getScale().y / 2)
	    pos = lockTarget->getPos();
	  else
	    {
	      pos.x += tempPos3.x;
	      pos.y += tempPos3.y;
	    }
	  double dist = sqrt((pos.x - oldPos.x) * (pos.x - oldPos.x) + (pos.y - oldPos.y) * (pos.y - oldPos.y));
	  range -= dist;
	}
    }
}
