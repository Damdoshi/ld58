// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:27:39 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	<math.h>
#include	"Map.hpp"
#include	"Border.hpp"

Border		border;

Tile		&Map::MapDim::operator[](int	x)
{
  if (t == NULL)
    return (border);
  if (x < 0 || x >= (int)w)
    return (border);
  return (t[x]);
}

Tile		&Map::MapDim::operator[](double	x)
{
  return ((*this)[(int)round(x)]);
}

Map::MapDim::MapDim(Tile			*_t,
		    size_t			_w)
  : t(_t),
    w(_w)
{}

Map::MapDim::~MapDim(void)
{}

Map::MapDim	Map::operator[](int		y)
{
  if (y < 0 || y >= size.y)
    return (MapDim(NULL, 0));
  return (MapDim(&tiles.data()[y * size.x], size.x));
}

Map::MapDim	Map::operator[](double		y)
{
  return ((*this)[(int)round(y)]);
}

