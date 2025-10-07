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
#include		"StrategicBoard.hpp"

t_bunny_response	StrategicBoard::Key(t_bunny_event_state	state,
					    t_bunny_keysym		sym)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    {
      prog.SetContext(Program::MAIN_MENU);
      return (SWITCH_CONTEXT);
    }
  return (GO_ON);
}
