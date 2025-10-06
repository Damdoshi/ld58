// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/10/2025 12:22:57 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

void			Warfield::KeyCamera(void)
{
  if (bunny_get_keyboard()[BKS_PAGEUP])
    ingame.map.Tilt(-0.1);
  if (bunny_get_keyboard()[BKS_PAGEDOWN])
    ingame.map.Tilt(+0.1);
  if (/*bunny_get_keyboard()[BKS_A] ||
	bunny_get_keyboard()[BKS_Q] ||*/
      bunny_get_keyboard()[BKS_LEFT])
    ingame.cameraPos.x -= 3;
  if (//bunny_get_keyboard()[BKS_D] ||
      bunny_get_keyboard()[BKS_RIGHT])
    ingame.cameraPos.x += 3;
  if (//bunny_get_keyboard()[BKS_Z] ||
      bunny_get_keyboard()[BKS_UP])
    ingame.cameraPos.y -= 3;
  if (//bunny_get_keyboard()[BKS_S] ||
      bunny_get_keyboard()[BKS_DOWN])
    ingame.cameraPos.y += 3;
  ingame.moveHero();
  if (bunny_get_keyboard()[BKS_SPACE])
    ingame.fireGun();

  if (ingame.cameraPos.x < 0)
    ingame.cameraPos.x = 0;
  if (ingame.cameraPos.x + prog.screen->buffer.width >= ingame.map.size.x)
    ingame.cameraPos.x = ingame.map.size.x - prog.screen->buffer.width;

  // return ;
  if (bunny_get_keyboard()[BKS_SUBTRACT])
    {
      ingame.cameraPos.x -= 1;
      ingame.cameraPos.y -= 1;
      ingame.cameraPos.w += 2;
      ingame.cameraPos.h += 2;
    }
  if (bunny_get_keyboard()[BKS_ADD])
    {
      ingame.cameraPos.x += 1;
      ingame.cameraPos.y += 1;
      ingame.cameraPos.w -= 2;
      ingame.cameraPos.h -= 2;
    }

  Move(t_bunny_position{});
}
