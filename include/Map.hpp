// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 12:02:06 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__MAP_HPP__
# define		__MAP_HPP__
# include		"Tile.hpp"
# include		"Unit.hpp"

class			Map
{
public:
  class			MapDim
  {
    Map			&map;

    Tile		&operator[](int				x);
    Tile		&operator[](double			x);

    MapDim(Map		&r);
    ~MapDim(void);
  };
  std::vector<Unit>	units;

  MapDim		operator[](int				y);
  MapDim		operator[](double			y);

  bool			LoadLevel(const std::string		&lvl);

  Map(void);
  ~Map(void);
};

#endif	//		__MAP_HPP__
