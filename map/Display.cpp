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
  std::shared_ptr<ef::Bpixelarray> lmap(std::make_shared<ef::Bpixelarray>(*mappx));

  acc = 0;
  bunny_clear(&screen.GetClip()->buffer, BLACK);
  bunny_clear(&mappx->buffer, BLACK);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      {
	Tile	&sand = y < size.y ? tiles[x + y * size.x] : border;
	Tile	&water = y < size.y ? waters[x + y * size.x] : border;

	hs = sand.Height() * tilt + 1;
	ef::AcuPos line[2] = {
	  {(double)x, y + hs    + 5 * (Tile::MaxHeight + 5), 0},
	  {(double)x, (double)y + 5 * (Tile::MaxHeight + 5), 0}
	};
	auto color = sand.GetDisplayColor();

	if ((int)(x + y * 1.5) % 20 == 0 || (int)(x - y * 1.5) % 20 == 0)
	  color |= COLOR(0, 127, 127, 127);
	if (!((int)((x + y * 1.5) / 20) % 2 || ((int)(x - y * 1.5) / 20) % 2))
	  color |= COLOR(0, 31, 31, 31);
	lmap->setLine(line[0], line[1], color);

	// A unit is here
	if (acc < objs.size() && round(objs[acc]->getPos().x) == x && round(objs[acc]->getPos().y) == y)
	  {
	    // To avoid having the shared ptr deleting screen, make a bpixelarray view
	    bunny_set_geometry(&mappx->buffer, BGY_LINES, (t_bunny_vertex_array *)&lmap->lineVec, NULL);
	    lmap->lineVec.length = 0;

	    objs[acc]->display(lmap, ef::AcuPos{0, hs + 5 * (Tile::MaxHeight + 5), 0});
	    acc++;
	  }

	if (water.Height() != 0)
	  {
	    if (tilt > 0)
	      hw = water.Height() * tilt + 1;
	    else
	      hw = 0;
	    ef::AcuPos line[2] = {
	      {(double)x, y + hs + hw + 5 * (Tile::MaxHeight + 5), 0},
	      {(double)x, (double)y   + 5 * (Tile::MaxHeight + 5), 0}
	    };

	    lmap->setLine(line[0], line[1], water.GetDisplayColor());
	  }
      }

  bunny_set_geometry(&mappx->buffer, BGY_LINES, (t_bunny_vertex_array *)&lmap->lineVec, NULL);
  lmap->lineVec.length = 0;

  /*
  if (area.x < 0)
    area.x = 0;
  if (area.x + area.w > mappx->buffer.width)
    area.x = mappx->buffer.width - area.w;
  if (area.y < 0)
    area.y = 0;
  if (area.y + area.h > mappx->buffer.height)
    area.y = mappx->buffer.height - area.h;
  */

  mappx->clip_x_position = area.x;
  mappx->clip_y_position = area.y;
  mappx->clip_width = area.w;
  mappx->clip_height = area.h;
  mappx->scale.x = (double)screen.GetClip()->buffer.width / mappx->clip_width;
  mappx->scale.y = (double)screen.GetClip()->buffer.height / mappx->clip_height;
  bunny_blit(&screen.GetClip()->buffer, mappx, NULL);
}
