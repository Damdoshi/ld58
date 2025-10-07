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

void		Map::Water(void)
{
  std::vector<int> h;
  std::vector<int> w;
  int		y;
  int		x;

  h.resize(size.x * size.y);
  w.resize(size.x * size.y);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      {
	h[x + y * size.x] = WaterTop(x, y);
	w[x + y * size.x] = waters[x + y * size.x].height;
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
	  int	tx = access[str[i] - 1].x + x;
	  int	ty = access[str[i] - 1].y + y;

	  if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
	    continue ;
	  for (int mx = 0; mx < 3 && (a(x, y) > a(tx, ty)) && w[x + y * size.x] > 0; ++mx)
	    {
	      a(x, y) -= 1;
	      a(tx, ty) += 1;
	      w[x + y * size.x] -= 1;
	      w[tx + ty * size.x] += 1;
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      waters[x + y * size.x].height = w[x + y * size.x];
}

