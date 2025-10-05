// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 18:49:36 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	<algorithm>
#include	"Border.hpp"
#include	"Map.hpp"

extern Border	border;

Tile		&get_tile(std::vector<Tile>	&tiles,
			  int			tw,
			  t_bunny_area		area,
			  double		xcoef,
			  double		ycoef)
{
  t_bunny_position pos;

  pos.x = xcoef * area.w + area.x;
  pos.y = ycoef * area.h + area.y;
  if (pos.x < 0 || pos.y < 0 || pos.x >= tw || pos.y >= (int)tiles.size() / tw)
    return (border);
  return (tiles[pos.x + pos.y * tw]);
}

bool		comp(ef::Object			*a,
		     ef::Object			*b)
{
  if (a->getPos().y < b->getPos().y)
    return (true);
  if (a->getPos().x < b->getPos().x)
    return (true);
  return (false);
}

void		Map::Display(ef::Bpixelarray	&screen,
			     t_bunny_area	area)
{
  double	hs;
  double	hw;
  int		y;
  int		x;

  // On commence par trier
  objs.clear();
  objs.resize(units[0]->size() + units[1]->size() + projs[0]->size() + projs[1]->size());
  size_t acc = 0;
  for (size_t i = 0; i < units[0]->size(); ++i)
    objs[acc++] = (*units[0])[i].get();
  for (size_t i = 0; i < units[1]->size(); ++i)
    objs[acc++] = (*units[1])[i].get();
  for (size_t i = 0; i < projs[0]->size(); ++i)
    objs[acc++] = (*projs[0])[i].get();
  for (size_t i = 0; i < projs[1]->size(); ++i)
    objs[acc++] = (*projs[1])[i].get();
  std::sort(objs.begin(), objs.end(), comp);

  acc = 0;
  for (y = 0; y < screen.GetSize().y + -tilt * 255; ++y)
    for (x = 0; x < screen.GetSize().x; ++x)
      {
	Tile	&sand = get_tile(tiles, size.x, area, (double)x / screen.GetSize().x, (double)y / screen.GetSize().y);
	Tile	&water = get_tile(waters, size.x, area, (double)x / screen.GetSize().x, (double)y / screen.GetSize().y);

	hs = sand.Height() * tilt + 1;
	ef::AcuPos line[2] = {
	  {(double)x, y + hs, 0},
	  {(double)x, (double)y, 0}
	};
	// if (!bwater)
	screen.setLine(line[0], line[1], sand.GetDisplayColor());

	// A unit is here
	if (acc < objs.size() && round(objs[acc]->getPos().x) == sand.GetPos().x && round(objs[acc]->getPos().y) == sand.GetPos().y)
	  {
	    // To avoid having the shared ptr deleting screen, make a bpixelarray view
	    objs[acc]->display(std::make_shared<ef::Bpixelarray>(*screen.GetClip()), ef::AcuPos{(double)round(area.x), (double)round(area.y) + hs, 0});
	    acc++;
	  }

	if (water.Height() != 0)
	  {
	    if (tilt > 0)
	      hw = water.Height() * tilt + 1;
	    else
	      hw = 0;
	    ef::AcuPos line[2] = {
	      {(double)x, y + hs + hw, 0},
	      {(double)x, (double)y, 0}
	    };
	    // if (bwater)
	    screen.setLine(line[0], line[1], water.GetDisplayColor());
	  }
      }
}
