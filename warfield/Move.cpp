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
  (void)rel;
  prog.realmouse = prog.GetMouseRealPosition();
  prog.ingamemouse.x = prog.realmouse.x + prog.ingame.cameraPos.x;
  prog.ingamemouse.y = prog.realmouse.y + prog.ingame.cameraPos.y;

  if (prog.realmouse.x <= 0)
    ingame.cameraPos.x -= 3;
  if (prog.realmouse.x >= prog.screen->buffer.width - 1)
    ingame.cameraPos.x += 3;
  if (prog.realmouse.y <= 0)
    ingame.cameraPos.y -= 3;
  if (prog.realmouse.y >= prog.screen->buffer.height - 1)
    ingame.cameraPos.y += 3;

  if (ingame.cameraPos.x < 0)
    ingame.cameraPos.x = 0;
  else if (ingame.cameraPos.x + prog.screen->buffer.width >= ingame.map.size.x)
    ingame.cameraPos.x = ingame.map.size.x - prog.screen->buffer.width;
  if (ingame.cameraPos.y < 0)
    ingame.cameraPos.y = 0;
  if (ingame.cameraPos.y + prog.screen->buffer.height >= ingame.map.size.y + 5 * (Tile::MaxHeight + 5))
    ingame.cameraPos.y = (ingame.map.size.y + 5 * (Tile::MaxHeight + 5)) - prog.screen->buffer.height;


  bool			visible = false;

  if (prog.realmouse.x == 0 || prog.realmouse.y == 0 || prog.realmouse.x == prog.screen->buffer.width - 1 || prog.realmouse.y == prog.screen->buffer.height - 1)
    visible = true;
  bunny_set_mouse_visibility(prog.win[0], visible);
  return (GO_ON);
}

