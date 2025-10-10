// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:51:39 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Tile.hpp"

int		Tile::Hit(int		power,
			  bool		rock)
{
  int		opower = 0;

  if (rock == false && type == ROCK)
    return (0);
  // Ca pourrait etre mathématiquement fait en O(1)
  // Mais mon cerveau est tout mou.
  if (power > 0)
    {
      while (hp < power)
	{
	  power -= hp;
	  hp = hp_per_height;
	  opower += 1;
	  if ((height -= 1) <= 0)
	    {
	      height = 0;
	      return (opower);
	    }
	}
      if (hp > power)
	hp -= power;
    }
  power *= -1;
  height += power / (int)hp_per_height;
  hp += power % (int)hp_per_height;
  return (-power / (int)hp_per_height);
}

