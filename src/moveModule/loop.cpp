#include "moveModule.hh"
#include "Map.hpp"
//#include <iostream>

void ef::MoveModule::loop(AcuPos &pos,
			  double &rota,
			  Map &map,
			  double unitSize)
{
  if (nextPosition.x == -1 && nextPosition.y == -1 && nextPosition.z == -1)
    {
      if (path.size() != 0)
	{
	  nextPosition = path[path.size() - 1];
	  path.pop_back();
	}
      else
	return;
    }
  if (pos.x == nextPosition.x && pos.y == nextPosition.y)
    {
      nextPosition.x = -1;
      nextPosition.y = -1;
      nextPosition.z = -1;
      return;
    }
  // check rotation
  AcuPos tempPos(cos(rota) * speed, sin(rota) * speed, 0);
  AcuPos tempPos3(cos(rota + M_PI / 2) * speed, sin(rota + M_PI / 2) * speed, 0);
  AcuPos tempPos2(nextPosition.x - pos.x, nextPosition.y - pos.y, 0);
  double dist1 = tempPos.x * tempPos.x + tempPos.y * tempPos.y;
  double dist2 = tempPos2.x * tempPos2.x + tempPos2.y * tempPos2.y;

  double angle = (tempPos.x * tempPos2.x + tempPos.y * tempPos2.y) / sqrt(dist1 * dist2);

  //std::cout << "MoveModule::loop : angle " << angle << " rota " << rota << std::endl;

  //std::cout << "MoveModule::loop : pos " << pos.x << " " << pos.y << " nextPosition " << nextPosition.x << " " << nextPosition.y << std::endl;
  //std::cout << "movemodule::loop : cond1 " << (angle < rotaSpeed * rotaSpeedMul * 5) << " cond2 " << (angle > -rotaSpeed * rotaSpeedMul * 5) << std::endl;
  if (angle < rotaSpeed * 5 && angle > -rotaSpeed * 5)
    rota = rota - angle;
  else if (angle > rotaSpeed)
    rota -= rotaSpeed;
  else if (angle < -rotaSpeed)
    rota += rotaSpeed;

  // move
  double dist = sqrt(dist2) / 4;
  if (dist < 5)
    dist = 5;
  //std::cout << "movemodule::loop : dist " << dist << " angle " << angle << std::endl;
  if (angle < rotaSpeed * dist && angle > -rotaSpeed * dist)
    {
      // test map
      t_bunny_area tempArea;
      tempArea.x = pos.x + tempPos3.x - unitSize / 2;
      tempArea.y = pos.y + tempPos3.y - unitSize / 2;
      tempArea.w = unitSize;
      temparea.h = unitSize;
      bool canMove = IsStableEnough(tempArea, maxDivergeance);

      if ((tempPos3.x > 0 && nextPosition.x > pos.x && pos.x + tempPos3.x > nextPosition.x) ||
	  (tempPos3.x < 0 && nextPosition.x < pos.x && pos.x + tempPos3.x < nextPosition.x))
	pos.x = nextPosition.x;
      else if (canMove)
	pos.x += tempPos3.x;
      if ((tempPos3.y > 0 && nextPosition.y > pos.y && pos.y + tempPos3.y > nextPosition.y) ||
	  (tempPos3.y < 0 && nextPosition.y < pos.y && pos.y + tempPos3.y < nextPosition.y))
	pos.y = nextPosition.y;
      else if (canMove)
	pos.y += tempPos3.y;
      if (pos.x == nextPosition.x && pos.y == nextPosition.y)
	{
	  if (path.size() != 0)
	    {
	      nextPosition = path[path.size() - 1];
	      path.pop_back();
	    }
	  else
	    {
	      nextPosition.x = -1;
	      nextPosition.y = -1;
	      nextPosition.z = -1;
	    }
	}
    }
}

