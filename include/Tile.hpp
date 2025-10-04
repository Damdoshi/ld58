// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 12:02:06 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__TILE_HPP__
# define		__TILE_HPP__
# include		<stdlib.h>
# include		<lapin.h>

class			Unit;
class			Tile
{
public:
  enum			Type
    {
      WATER		= BLUE,
      SAND		= YELLOW,
      MINERAL		= RED,
      ROCK		= GRAY(128)
    };
protected:
  Type			type;
  double		height;
  double		hp_per_height;
  double		hp;
  Unit			*over = NULL;

public:
  static constexpr double MaxHeight = 100;

  double		Height(void) const;

  virtual void		Hit(int				power);

  virtual bool		CanGoOver(void) const;
  virtual Unit		*UnitOver(void);
  virtual void		SetUnitOver(Unit		&unit);
  virtual void		NoUnitOver(void);

  unsigned int		GetDisplayColor(void) const;

  void			SetTile(unsigned int		mat,
				unsigned int		hei);

  Tile(double		h = 0,
       double		hpph = 1);
  virtual ~Tile(void);
};

#endif	//		__TILE_HPP__
