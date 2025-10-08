// EFRITS
// project:     rts
// created on:  2024-02-12 - 18:18 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: isInRange implementation

#include "Bpixelarray.hh"

#include <iostream>

int ef::Pos::isInRange(ef::Pos other, int _x, int _y)
{
  if (other.x >= x - _x && other.x <= x + _x && other.y >= y - _y && other.y <= y + _y)
    {
      /*
      if (_x == 0 && _y == 0)
	{
	  std::cout << "isInRange YES!!!" << std::endl;
	  std::cout << "isInRange other pos x : " << other.x << " y : " << other.y << std::endl;
	  std::cout << "isInRange US pos x : " << x << " y : " << y << std::endl;
	}
      else
	  std::cout << "isInRange range x : " << _x << " y : " << _y << std::endl;
      */
      int xdist = other.x - x;
      int ydist = other.y - y;
      return xdist * xdist + ydist * ydist;
    }
  return -1;
}

