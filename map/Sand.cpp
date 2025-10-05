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

void		Map::Sand(void)
{
  std::vector<int> h;
  int		y;
  int		x;

  h.resize(size.x * size.y);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      h[x + y * size.x] = SandTop(x, y);

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
      if (tiles[x + y * size.x].type == Tile::SAND)
	{
	  for (int i = 0; i < 4; ++i)
	    {
	      int	tx = access[str[i] - 1].x + x;
	      int	ty = access[str[i] - 1].y + y;

	      if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
		continue ;
	      if (a(x, y) - 1 > a(tx, ty))
		{
		  a(x, y) -= 1;
		  a(tx, ty) += 1;
		}
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      tiles[x + y * size.x].height = a(x, y);

}
