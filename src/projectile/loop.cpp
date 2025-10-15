#include "projectile.hh"
#include "Map.hpp"

bool ef::Projectile::loop(Map &map)
{
  //std::cout << "projectile loop lockTarget " << (lockTarget == nullptr) << std::endl;
  AcuPos target(0, 0, 0);
  if (lockTarget.get() != nullptr)
    target = lockTarget->getPos();
  else
    target = destination;
  if (target.x != -1 && target.y != -1)
    {
      //std::cout << "projectile loop go to target.x " << target.x << " y " << target.y << std::endl;
      // check rotation
      AcuPos tempPos(cos(getRota()) * speed, sin(getRota()) * speed, 0);
      AcuPos tempPos3(cos(getRota() + M_PI / 2) * speed, sin(getRota() + M_PI / 2) * speed, 0);
      AcuPos tempPos2(target.x - getPos().x, target.y - getPos().y, 0);
      double dist1 = tempPos.x * tempPos.x + tempPos.y * tempPos.y;
      double dist2 = tempPos2.x * tempPos2.x + tempPos2.y * tempPos2.y;
      double angle = 0;
      if (sqrt(dist1 * dist2) != 0)
	angle = (tempPos.x * tempPos2.x + tempPos.y * tempPos2.y) / sqrt(dist1 * dist2);

      //std::cout << "projectile loop angle " << angle << std::endl;
      if (angle > rotaSpeed)
	setRota(getRota() - rotaSpeed);
      else if (angle < -rotaSpeed)
	setRota(getRota() + rotaSpeed);
      else
	setRota(getRota() - angle);

      // movement
      //std::cout << "projectile loop range" << range << std::endl;
      if (range > 0)
	{
	  AcuPos oldPos = pos;
	  //std::cout << "projectile::loop : posx " << pos.x + tempPos3.x << " posy " << pos.y + tempPos3.y << " targetx " << lockTarget->getPos().x << " targety " << lockTarget->getPos().y << std::endl;
	  double maxDivergeance = 2;
	  t_bunny_area startArea;
	  startArea.x = pos.x;
	  startArea.y = pos.y;
	  startArea.w = 1;
	  startArea.h = 1;
	  t_bunny_position endArea;
	  endArea.x = pos.x + tempPos3.x;
	  endArea.y = pos.y + tempPos3.y;
	  bool canMove = map.IsMoveLegal(startArea, endArea, maxDivergeance);
	  //std::cout << "projectile loop canMove" << canMove << std::endl;

	  if (pos.x + tempPos3.x < target.x + 1 &&
	      pos.x + tempPos3.x > target.x - 1 &&
	      pos.y + tempPos3.y < target.y + 1 &&
	      pos.y + tempPos3.y > target.y - 1)
	    {
	      pos = target;
	      range = 0;
	      //std::cout << "projectile loop set pos.x " << pos.x << " y " << pos.y << std::endl;
	    }
	  else if (canMove || projType == ARC)
	    {
	      //std::cout << "projectile loop before pos.x " << pos.x << " y " << pos.y << std::endl;
	      pos.x += tempPos3.x;
	      pos.y += tempPos3.y;
	      if (projType == ARC)
		{
		  //std::cout << "projectile loop distToGo " << distToGo << std::endl;
		  pos.z = sin(M_PI / distToGo * currDistToGo) * -distToGo;
		}
	      //std::cout << "projectile loop after pos.x " << pos.x << " y " << pos.y << std::endl;
	    }
	  else
	    return true;
	  double dist = sqrt((pos.x - oldPos.x) * (pos.x - oldPos.x) + (pos.y - oldPos.y) * (pos.y - oldPos.y));
	  range -= dist;
	  currDistToGo -= dist;
	}
    }
  lifeTime -= 1;
  return false;
}
