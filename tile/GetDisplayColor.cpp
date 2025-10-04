// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:04:18 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Tile.hpp"

unsigned int		Tile::GetDisplayColor(void) const
{
  t_bunny_color		col;
  double		appreciation = ((double)height / MaxHeight) / 2;

  col.full = type;
  col.argb[RED_CMP] *= appreciation + 0.5;
  col.argb[GREEN_CMP] *= appreciation + 0.5;
  col.argb[BLUE_CMP] *= appreciation + 0.5;
  return (col.full);
}
