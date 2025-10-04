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
# include		<lapin.h>
# include		<vector>
# include		"Tile.hpp"
# include		"Unit.hpp"

class			Map
{
public:
  class			MapDim
  {
  private:
    Tile		*t;
    size_t		w;

  public:
    Tile		&operator[](int				x);
    Tile		&operator[](double			x);

  private:
    MapDim(Tile		*t,
	   size_t	w);
    ~MapDim(void);
    friend ::Map;
  };
  std::vector<Tile>	tiles;
  t_bunny_size		size;

  MapDim		operator[](int				y);
  MapDim		operator[](double			y);

  bool			IsStableEnough(t_bunny_area		area,
				       double			max_divergeance);
  double		AverageHeight(t_bunny_area		area);

  bool			LoadLevel(const std::string		&lvl) {}

  Map(void) = default;
  ~Map(void) {}
};

#endif	//		__MAP_HPP__
