// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 20:51:43 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Program.hpp"
#include		"Warfield.hpp"

t_bunny_response	Warfield::Key(t_bunny_event_state	state,
				      t_bunny_keysym		sym)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_P)
    {
      t_bunny_area area;
      area.x = 0;
      area.y = 0;
      area.w = 1000;
      area.h = 1000;
      ingame.selectUnit(area);
    }
  if (sym == BKS_M)
    {
      const t_bunny_position *mousePos = &prog.ingamemouse;
      t_bunny_position pos;

      pos.x = 80;
      pos.y = 80;
      ingame.moveUnit(pos, false);
    }
  if (sym == BKS_L)
    {
      const t_bunny_position *mousePos = &prog.ingamemouse;
      t_bunny_position pos;

      pos.x = 200;
      pos.y = 80;
      ingame.moveUnit(pos, false);
    }
  if (sym == BKS_ESCAPE)
    {
      prog.SetContext(Program::MAIN_MENU);
      return (SWITCH_CONTEXT);
    }
  return (GO_ON);
}
