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
# include		"Bconf.hh"
# include		"Bpixelarray.hh"
# include		"Tile.hpp"
# include		"Unit.hpp"
# include		"projectile.hh"

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
  std::vector<std::shared_ptr<ef::Unit>> *units[2];
  std::vector<std::shared_ptr<ef::Projectile>> *projs[2];
  std::vector<ef::Object*> objs; // sorted units and projs
  std::vector<Tile>	tiles;
  std::vector<Tile>	waters;
  std::vector<char>	zbuffer;
  t_bunny_picture	*mappx;
  t_bunny_size		size;
  double		tilt; // Coefficient de hauteur - 0 de base

  
  
  double		Tilt(double				tilt);

  MapDim		operator[](int				y);
  MapDim		operator[](double			y);

  bool			IsStableEnough(t_bunny_area		area,
				       double			max_divergeance);

  // Top left rect
  bool			IsMoveLegal(t_bunny_area		from,
				    t_bunny_area		to,
				    double			max_divergeance);
  bool			IsMoveLegal(t_bunny_area		from,
				    t_bunny_position		to,
				    double			max_divergeance);
  double		AverageHeight(t_bunny_area		area);

  int			SandTop(int				x,
				int				y);
  int			WaterTop(int				x,
				 int				y);

  bool			OnFloor(int				x,
				int				y,
				int				z_feet);
  bool			Buried(int				x,
			       int				y,
			       int				z_head);
  bool			Underwater(int				x,
				   int				y,
				   int				z_head);

  int			Hit(t_bunny_area			area,
			    int					power,
			    bool				rock);
  int			Hit(t_bunny_position			pos,
			    double				rad,
			    int					power,
			    bool				rock);

  void			Sand(t_bunny_area			a);
  void			Water(t_bunny_area			b,
			      int				phase);

  bool			LoadConf(ef::Bconf			&conf);
  bool			LoadConf(const std::string		&conf);

  void			Display(ef::Bpixelarray			&bpix,
				t_bunny_area			area);

  Map(std::vector<std::shared_ptr<ef::Unit>> &mu,
      std::vector<std::shared_ptr<ef::Unit>> &eu,
      std::vector<std::shared_ptr<ef::Projectile>> &mp,
      std::vector<std::shared_ptr<ef::Projectile>> &ep);
  ~Map(void);
};


#endif	//		__MAP_HPP__
