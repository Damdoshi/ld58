// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 15:46:56 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Map.hpp"

void			Map::Hit(t_bunny_area		area,
				 int			power,
				 bool			rock)
{
  int			i;
  int			j;

  for (j = 0; j < area.h; ++j)
    for (i = 0; i < area.w; ++i)
      {
	int		x = i + area.x;
	int		y = j + area.y;

	tiles[x + y * size.x].Hit(power, rock);
      }
}

void			Map::Hit(t_bunny_position	area,
				 double			rad,
				 int			power,
				 bool			rock)
{
  int			i;
  int			j;

  for (j = -rad; j < rad; ++j)
    for (i = -rad; i < rad; ++i)
      {
	double		d = i * i + j * j;

	if (d > rad * rad)
	  continue ;
	int		x = i + area.x;
	int		y = j + area.y;

	d = sqrt(d);
	d = 1 - d / rad;
	d *= power;
	tiles[x + y * size.x].Hit(d, rock);
      }
}

