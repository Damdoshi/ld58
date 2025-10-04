// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 18:49:36 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Map.hpp"

Tile		&get_tile(std::vector<Tile>	&tiles,
			  int			tw,
			  t_bunny_area		area,
			  double		xcoef,
			  double		ycoef)
{
  t_bunny_position pos;

  pos.x = xcoef * area.w;
  pos.y = ycoef * area.h;
  return (tiles[(pos.x + area.x) * tw + pos.y + area.y]);
}

void		Map::Display(ef::Bpixelarray	&screen,
			     t_bunny_area	area)
{
  double	hs;
  double	hw;
  int		y;
  int		x;

  // Ceci n'est pas une gestion du zoom
  // mais un filet de sécurité qui peut entrainer une déformation
  // l'objectif est simplement d'eviter le plantage
  if (area.x < 0)
    area.x = 0;
  if (area.y < 0)
    area.y = 0;
  if (area.x + area.w >= size.x)
    if ((area.x = size.x - area.w) < 0)
      {
	area.x = 0;
	area.w = size.x;
      }
  if (area.y + area.h >= size.y)
    if ((area.y = size.y - area.h) < 0)
      {
	area.y = 0;
	area.h = size.y;
      }

  for (y = 0; y < screen.GetSize().y; ++y)
    for (x = 0; x < screen.GetSize().x; ++x)
      {
	Tile	&sand = get_tile(tiles, size.x, area, (double)x / screen.GetSize().x, (double)y / screen.GetSize().y);
	Tile	&water = get_tile(waters, size.x, area, (double)x / screen.GetSize().x, (double)y / screen.GetSize().y);

	hs = sand.Height() * tilt + 1;
	ef::AcuPos line[2] = {
	  {(double)x, y + hs, 0},
	  {(double)x, (double)y, 0}
	};
	screen.setLine(line[0], line[1], sand.GetDisplayColor());

	if (water.Height() != 0)
	  {
	    if (tilt > 0)
	      hw = water.Height() * tilt + 1;
	    else
	      hw = 0;
	    ef::AcuPos line[2] = {
	      {(double)x, y + hs + hw, 0},
	      {(double)x, (double)y, 0}
	    };
	    screen.setLine(line[0], line[1], water.GetDisplayColor());
	  }
      }
}
