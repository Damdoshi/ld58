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

typedef struct		s_packet
{
  t_bunny_area		area;
  int			phase;
}			t_packet;

// Thunks compatibles avec bunny_thread_push
static void sand_thunk(void* data, void* param) {
  Map* m = static_cast<Map*>(data);
  const t_bunny_area* a = static_cast<const t_bunny_area*>(param);
  m->Sand(*a);
}

static void water_thunk(void* data, void* param) {
  Map* m = static_cast<Map*>(data);
  const t_packet* a = static_cast<const t_packet*>(param);
  m->Water(a->area, a->phase);
}



t_bunny_response Warfield::Loop()
{
  constexpr int T     = 8;   // nombre de zones / threads
  constexpr int HALO  = 1;   // recouvrement (>=1 conseillé)
  static int   phase4 = 0;   // 0..3 : pixel actif dans le sous-échantillonnage 2x2

  t_packet pkt[T];

  // --- Découpe en bandes VERTICALES (pleine hauteur) ---
  const int Wg = ingame.map.size.x;
  const int Hg = ingame.map.size.y;
  const int base = Wg / T;
  const int rem  = Wg % T;

  int x = 0;
  for (int i = 0; i < T; ++i)
    {
      int wcore = base + (i < rem ? 1 : 0);     // largeur "coeur" (sans halo)
      int xcore = x;
      x += wcore;

      // Appliquer le halo (en lecture/écriture, mais on évite la concurrence via l’ordonnancement pair/impair)
      int x0 = xcore - HALO;
      int w  = wcore + 2 * HALO;

      // Clamp dans les bornes globales
      if (x0 < 0) { w += x0; x0 = 0; }
      if (x0 + w > Wg) w = Wg - x0;

      pkt[i].area.x = x0;
      pkt[i].area.y = 0;
      pkt[i].area.w = w;
      pkt[i].area.h = Hg;

      pkt[i].phase  = phase4; // la même phase pour toutes les zones ce frame
  }

  static int economie = 0;


  if (economie % 4 == 0)
    {
      // === PHASE SABLE ===
      // Lancer zones paires (0,2,4,...) en parallèle
      for (int i = 0; i < T; i += 2)
	bunny_thread_push(prog.pool, sand_thunk, &ingame.map, &pkt[i].area);
      bunny_thread_wait_completion(prog.pool);
    }
  else if (economie % 4 == 1)
    {
      // Puis zones impaires (1,3,5,...) en parallèle
      for (int i = 1; i < T; i += 2)
	bunny_thread_push(prog.pool, sand_thunk, &ingame.map, &pkt[i].area);
      bunny_thread_wait_completion(prog.pool);
    }
  else if (economie % 4 == 2)
    {
      // === PHASE EAU ===
      for (int i = 0; i < T; i += 2)
	bunny_thread_push(prog.pool, water_thunk, &ingame.map, &pkt[i]);
      bunny_thread_wait_completion(prog.pool);
    }
  else if (economie % 4 == 3)
    {
      for (int i = 1; i < T; i += 2)
	bunny_thread_push(prog.pool, water_thunk, &ingame.map, &pkt[i]);
      bunny_thread_wait_completion(prog.pool);
      phase4 = (phase4 + 1) & 3;
    }
  economie += 1;

  KeyCamera();
  ingame.loop();
  if (ingame.hasLoose())
    {
      bunny_sound_stop(&ingame.music->sound);
      prog.SetContext(Program::MAIN_MENU);
      return (SWITCH_CONTEXT);
    }
  if (ingame.hasWin())
    {
      bunny_sound_stop(&ingame.music->sound);
      prog.SetContext(Program::MAIN_MENU);
      return (SWITCH_CONTEXT);
    }
  return GO_ON;
}

/*

t_bunny_response Warfield::Loop()
{
  constexpr int T = 2;
  t_packet p[T];

  // Découpe en bandes horizontales (toute la largeur, parts de hauteur)
  int base = ingame.map.size.y / T;
  int rem  = ingame.map.size.y % T;

  int y = 0;
  for (int i = 0; i < T; ++i) {
    int h = base + (i < rem ? 1 : 0);         // répartit le reste
    p[i].area.x = 0;
    p[i].area.y = y;
    p[i].area.w = ingame.map.size.x;                      // pleine largeur
    p[i].area.h = h;
    y += h;
  }

  for (int i = 0; i < T; ++i)
    bunny_thread_push(prog.pool, sand_thunk, &ingame.map, &p[i].area);
  bunny_thread_wait_completion(prog.pool);

  for (int i = 0; i < T; ++i)
    bunny_thread_push(prog.pool, water_thunk, &ingame.map, &p[i]);
  bunny_thread_wait_completion(prog.pool);

  KeyCamera();
  ingame.loop();
  return (GO_ON);
}
*/

/*
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
*/
