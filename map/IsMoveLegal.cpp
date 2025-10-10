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

  return (fabs(favg - tavg) < max_divergeance);
}

bool		Map::IsMoveLegal(t_bunny_area		from,
				 t_bunny_position	to,
				 double			max_divergeance)
{
  t_bunny_area	area {to.x, to.y, from.w, from.y};

  return (IsMoveLegal(from, area, max_divergeance));
}
