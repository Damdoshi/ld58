// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:49:36 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Tile.hpp"

Tile::Tile(double	h,
	   double	hpph)
  : height(h),
    hp_per_height(hpph),
    hp(hpph)
{
  random_col.argb[ALPHA_CMP] = 255;
  random_col.argb[RED_CMP] = rand() % 16;
  random_col.argb[GREEN_CMP] = random_col.argb[RED_CMP];
  random_col.argb[BLUE_CMP] = random_col.argb[RED_CMP];
}

Tile::~Tile(void)
{}

