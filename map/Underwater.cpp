// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 18:46:55 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Map.hpp"

bool			Map::Underwater(int		x,
					int		y,
					int		z)
{
  Tile			&t = (*this)[y][x];

  if (t.Height() > z)
    return (true);
  //std::cout << "map underwater water height " << waters[y * size.x + x].Height() << " vs height " << z + t.Height() << std::endl;
  return (waters[y * size.x + x].Height() > z + t.Height());
}

