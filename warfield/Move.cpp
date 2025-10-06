// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

t_bunny_response	Warfield::Move(const t_bunny_position &rel)
{
  prog.realmouse = prog.GetMouseRealPosition();
  prog.ingamemouse.x = prog.realmouse.x + prog.ingame.cameraPos.x;
  prog.ingamemouse.y = prog.realmouse.y + prog.ingame.cameraPos.y;
  return (GO_ON);
}

