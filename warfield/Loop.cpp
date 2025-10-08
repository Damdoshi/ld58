// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 20:54:26 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

static void		sand(void		*a,
			     void		*b)
{
  Map			*map = (Map*)a;

  map->Sand(*(t_bunny_area*)b);
}

static void		water(void		*a,
			      void		*b)
{
  Map			*map = (Map*)a;

  map->Water(*(t_bunny_area*)b);
}

t_bunny_response	Warfield::Loop(void)
{
  static t_bunny_area	area[8];
  int			cell;
  int			i;

  cell = ingame.map.size.x / NBRCELL(area);
  for (i = 0; i < NBRCELL(area); ++i)
    {
      area[i].x = i * cell;
      area[i].y = 0;
      area[i].w = cell;
      area[i].h = ingame.map.size.y;
    }
  KeyCamera();

  for (i = 0; i < NBRCELL(area); ++i)
    bunny_thread_push(prog.pool, sand, (void*)&ingame.map, &area[i]);
  bunny_thread_wait_completion(prog.pool);
  for (i = 0; i < NBRCELL(area); ++i)
    bunny_thread_push(prog.pool, water, (void*)&ingame.map, &area[i]);
  bunny_thread_wait_completion(prog.pool);
  ingame.loop();
  return (GO_ON);
}
