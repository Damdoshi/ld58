// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/10/2025 11:40:34 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Map.hpp"

Map::Map(std::vector<std::shared_ptr<ef::Unit>> &mu,
	 std::vector<std::shared_ptr<ef::Unit>> &eu,
	 std::vector<std::shared_ptr<ef::Projectile>> &mp,
	 std::vector<std::shared_ptr<ef::Projectile>> &ep)
{
  units[0] = &mu;
  units[1] = &eu;
  projs[0] = &mp;
  projs[1] = &ep;
  tilt = -0.5;
}

Map::~Map(void)
{}

