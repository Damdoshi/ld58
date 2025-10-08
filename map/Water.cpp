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

void		Map::Water(t_bunny_area		a)
{
  std::vector<int> h;
  std::vector<int> w;

  h.resize(size.x * size.y);
  w.resize(size.x * size.y);
  t_bunny_position size = {a.w, a.h};
  t_bunny_position start = {a.x, a.y};
  int		y;
  int		x;

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      {
	h[x + start.x + (y + start.y) * size.x] = WaterTop(x + start.x, y + start.y);
	w[x + start.x + (y + start.y) * size.x] = waters[x + start.x + (y + start.y) * size.x].height;
      }

  t_bunny_position access[4] =
    {
     {-1,  0},
     { 0, -1},
     {+1,  0},
     { 0, +1}
    };
  char		str[5] = {1, 2, 3, 4};

  strfry(str);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      for (int i = 0; i < 4 && w[y * size.x + x] > 0; ++i)
	{
	  int	tx = access[str[i] - 1].x + x + start.x;
	  int	ty = access[str[i] - 1].y + y + start.y;

	  if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
	    continue ;
	  for (int mx = 0; mx < 3 && (a(x + start.x, y + start.y) > a(tx, ty)) && w[x + start.x + (y + start.y) * size.x] > 0; ++mx)
	    {
	      a(x + start.x, y + start.y) -= 1;
	      a(tx, ty) += 1;
	      w[x + start.x + + (y + start.y) * size.x] -= 1;
	      w[tx + ty * size.x] += 1;
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      waters[x + start.x + (y + start.y) * size.x].height = w[x + start.x + (y + start.y) * size.x];
}

