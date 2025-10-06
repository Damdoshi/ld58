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
#include	"Program.hpp"
#include	"Border.hpp"
#include	"Map.hpp"

extern Border	border;

bool		comp(ef::Object			*a,
		     ef::Object			*b)
{
  if ((int)a->getPos().y != (int)b->getPos().y)
    return (a->getPos().y < b->getPos().y);
  return (a->getPos().x < b->getPos().x);
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
  /*
  for (acc = 0; acc < objs.size(); ++acc)
    {
      if (objs[acc]->getPos().x < 0 ||
	  objs[acc]->getPos().y < 0 ||
	  objs[acc]->getPos().x >= size.x ||
	  objs[acc]->getPos().y >= size.y)
	continue ;
      std::cout << "VALID MOB " << acc << std::endl;
      std::cout << objs[acc]->getPos().x << " " << objs[acc]->getPos().y << std::endl;
    }
  */
  
  std::sort(objs.begin(), objs.end(), comp);
  std::shared_ptr<ef::Bpixelarray> lmap(std::make_shared<ef::Bpixelarray>(*mappx));
  //std::cout << " size " << objs.size() << std::endl;
  /*
  for (acc = 0; acc < objs.size(); ++acc)
    {
      if (objs[acc]->getPos().x < 0 ||
	  objs[acc]->getPos().y < 0 ||
	  objs[acc]->getPos().x >= size.x ||
	  objs[acc]->getPos().y >= size.y)
	continue ;
      std::cout << "VALID MOB " << acc << std::endl;
      std::cout << objs[acc]->getPos().x << " " << objs[acc]->getPos().y << std::endl;
    }
  */
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

	/*if (x == 160 && y == 150)
	  puts("I'm shitting on all of this");*/
	// A unit is here
	while (acc < objs.size() && (int)objs[acc]->getPos().x == x && (int)objs[acc]->getPos().y == y)
	  {
	    //std::cout << "acc " << acc << std::endl;
	    // To avoid having the shared ptr deleting screen, make a bpixelarray view
	    if (lmap->lineVec.length)
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
  if (acc != objs.size())
    std::cout << "NOT PRINTED SHIT ________________________________________________________________" << std::endl;
  while (acc < objs.size())
    {
      std::cout << "acc " << acc << " OBJS X Y " << objs[acc]->getPos().x << " " << objs[acc]->getPos().y << std::endl;
      acc += 1;
    }

  if (lmap->lineVec.length)
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

  t_bunny_position	pos[2];
  unsigned int		colx[2] = {RED, GREEN};
  double		ang = (rand() % 2000) / 2000.0;
  double		off[2];

  off[0] = 5 * cos(2 * M_PI * ang);
  off[1] = 5 * sin(2 * M_PI * ang);
  pos[0].x = gprog->ingamemouse.x + off[0];
  pos[0].y = gprog->ingamemouse.y + off[1];

  off[0] = 5 * cos(2 * M_PI * ang + M_PI);
  off[1] = 5 * sin(2 * M_PI * ang + M_PI);
  pos[1].x = gprog->ingamemouse.x + off[0];
  pos[1].y = gprog->ingamemouse.y + off[1];
  bunny_set_line(&mappx->buffer, pos, colx);
  bunny_blit(&screen.GetClip()->buffer, mappx, NULL);
}
