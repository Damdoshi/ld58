// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 10/10/2025 11:09:11 ******************************************************
// damdoshi <damdoshi@aldrin.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Map.hpp"

bool		Map::IsMoveLegal(t_bunny_area		from,
				 t_bunny_area		to,
				 double			max_divergeance)
{
  double	favg = AverageHeight(from);
  double	tavg = AverageHeight(to);

  //std::cout << "map ismovelegal favg " << favg << " tavg " << tavg << " max_divergeance " << max_divergeance << std::endl;
  return (fabs(favg - tavg) < max_divergeance);
}

bool		Map::IsMoveLegal(t_bunny_area		from,
				 t_bunny_position	to,
				 double			max_divergeance)
{
  t_bunny_area	area {to.x, to.y, from.w, from.h};

  return (IsMoveLegal(from, area, max_divergeance));
}
