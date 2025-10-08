// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 15:46:56 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Map.hpp"

#define		a(xx, yy) h[(xx) + (yy) * size.x]

void		Map::Sand(t_bunny_area		a)
{
  std::vector<int> h;
  h.resize(size.x * size.y);

  t_bunny_position size = {a.w, a.h};
  t_bunny_position start = {a.x, a.y};
  int		y;
  int		x;

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      h[(x + start.x) + (y + start.y) * size.x] = SandTop(x + start.x, y + start.y);

  t_bunny_position access[] =
    {
     {-1, +0}, {+0, -1}, {+1,  0}, {+0, +1},
     {-1, -1}, {+1, -1}, {+1, +1}, {-1, +1},
     {-2, +0}, {+0, -2}, {+2,  0}, {+0, +2}
    };
  char		str[NBRCELL(access) + 1];
  int		max = NBRCELL(access) + 1;

  max = 2; // Saboté a deux
  int		i;

  for (i = 0; i < max; ++i)
    str[i] = i + 1;
  str[i] = 0;
  strfry(str);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      if (tiles[x + y * size.x].type == Tile::SAND)
	{
	  for (int i = 0; i < max; ++i)
	    {
	      int	tx = access[str[i] - 1].x + x + start.x;
	      int	ty = access[str[i] - 1].y + y + start.y;

	      if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
		continue ;
	      if (a(x + start.x, y + start.y) - 1 > a(tx, ty))
		{
		  a(start.y + x, start.y + y) -= 1;
		  a(tx, ty) += 1;
		}
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      tiles[(x + start.x) + (y + start.y) * size.x].height = a(x + start.x, y + start.y);
}
