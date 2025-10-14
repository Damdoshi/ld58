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
	      //std::cout << "Title hit height" << height << std::endl;
	      height = 0;
	      return (opower);
	    }
	}
      if (hp > power)
	hp -= power;
    }
  power *= -1;
  //std::cout << "Title hit hp_per_height " << hp_per_height << " power " << power << std::endl;
  height += power / (int)hp_per_height;
  if (height < 0)
    height = 0;
  hp += power % (int)hp_per_height;
  return (-power / (int)hp_per_height);
}

