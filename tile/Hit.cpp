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

void		Tile::Hit(int		power,
			  bool		rock)
{
  if (rock == false && type == ROCK)
    return ;
  // Ca pourrait etre mathématiquement fait en O(1)
  // Mais mon cerveau est tout mou.
  if (power > 0)
    {
      while (hp < power)
	{
	  power -= hp;
	  hp = hp_per_height;
	  if ((height -= 1) <= 0)
	    {
	      height = 0;
	      return ;
	    }
	}
      if (hp > power)
	hp -= power;
    }
  else
    {
      power *= -1;
      height += power / (int)hp_per_height;
      hp += power % (int)hp_per_height;
    }
}

