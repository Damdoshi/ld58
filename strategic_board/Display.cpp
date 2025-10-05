// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:31:17 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"StrategicBoard.hpp"

t_bunny_response	StrategicBoard::Display(void)
{
  std::shared_ptr<ef::Bpixelarray> tempPtr;
  t_bunny_clipable	&screen = prog.GetScreen();
  auto cp = ingame.cameraPos;
  auto tilt = ingame.map.tilt;

  ingame.map.tilt = 0;
  ingame.cameraPos.x = 0;
  ingame.cameraPos.y = 5 * (Tile::MaxHeight + 5);
  ingame.cameraPos.w = ingame.map.size.x;
  ingame.cameraPos.h = ingame.map.size.y;
  tempPtr.reset(new ef::Bpixelarray(*world_map));
  ingame.display(tempPtr, false);
  ingame.cameraPos = cp;
  ingame.map.tilt = tilt;

  bunny_blit(&screen.buffer, board_decor, NULL);
  bunny_blit(&screen.buffer, world_map, NULL);
  for (auto it = buttons.begin(); it != buttons.end(); ++it)
    if (it->second.font)
      {
	bunny_clear(&it->second.font->clipable.buffer, 0);
	bunny_draw(&it->second.font->clipable);
	bunny_blit(&screen.buffer, &it->second.font->clipable, NULL);
      }
  prog.Display();
  return (GO_ON);
}

