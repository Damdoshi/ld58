// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Editor.hpp"

t_bunny_response	Editor::Simulate(void)
{
  if (strcmp(focus->string, "Simulate") == 0)
    focus->string = "StopSimulation";
  else
    focus->string = "Simulate";
  bunny_clear(&focus->clipable.buffer, 0);
  bunny_draw(&focus->clipable);
  return (GO_ON);
}

