// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:59:15 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Map.hpp"

bool			Map::IsStableEnough(t_bunny_area		area,
					    double			maxd)
{
  double		avgh = 0;
  int			x;
  int			y;

  for (y = area.y; y < area.h + area.y; ++y)
    for (x = area.x; x < area.w + area.x; ++x)
      avgh += (*this)[y][x].Height();
  avgh /= area.h * area.w;
  for (y = area.y; y < area.h + area.y; ++y)
    for (x = area.x; x < area.w + area.x; ++x)
      if (fabs((*this)[y][x].Height() - avgh) > maxd)
	return (false);
  return (true);
}
