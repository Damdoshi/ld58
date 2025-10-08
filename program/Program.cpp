// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 12:48:42 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		<assert.h>
#include		"Program.hpp"
#include		"MainMenu.hpp"
#include		"Warfield.hpp"
#include		"StrategicBoard.hpp"

Program::Program(void)
  : current_context(INITIAL_CONTEXT),
    ingame("./lvl/00/lvl1.dab", *this)
{
  t_bunny_position	pos;

  assert((win = bunny_begin("./res/window.dab")));
  assert((conf = bunny_open_configuration("./res/program.dab", NULL)));
  assert(bunny_position_configuration("Screen", &pos, conf) == BD_OK);
  assert((screen = bunny_new_picture(pos.x, pos.y)));
  assert((pool = bunny_new_threadpool(8)));

  contexts[MAIN_MENU] = new MainMenu(*this);
  contexts[WARFIELD] = new Warfield(*this, ingame);
  contexts[STRATEGIC_BOARD] = new StrategicBoard(*this, ingame);

  if (!bunny_configuration_getf_int(conf, &freq, "Frequency"))
    freq = 60;
}

Program::~Program(void)
{
  if (screen)
    bunny_delete_clipable(screen);
  if (conf)
    bunny_delete_configuration(conf);
  if (win)
    bunny_end(win);
  if (pool)
    bunny_delete_threadpool(pool);
}

