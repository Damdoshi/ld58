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
  double		appreciation = ((double)height / MaxHeight) * 0.8;

  col.full = type;
  if (type == WATER)
    {
      col.argb[ALPHA_CMP] = 255 * (appreciation + 0.1);
    }
  else
    {
      col.argb[RED_CMP] *= appreciation + 0.1;
      col.argb[GREEN_CMP] *= appreciation + 0.1;
      col.argb[BLUE_CMP] *= appreciation + 0.1;
      col.full |= random_col.full;
    }
  return (col.full);
}

