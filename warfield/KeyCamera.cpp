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
      ingame.cameraPos.x = ingame.cameraPos.x + 1;// * 0.95;
      ingame.cameraPos.y = ingame.cameraPos.y + 1;// * 0.95;
      ingame.cameraPos.w = ingame.cameraPos.w - 1;// * 1.05;
      ingame.cameraPos.h = ingame.cameraPos.h- 1;// * 1.05;
    }
  if (bunny_get_keyboard()[BKS_ADD])
    {
      ingame.cameraPos.x = ingame.cameraPos.x - 1;// / 0.95;
      ingame.cameraPos.y = ingame.cameraPos.y - 1;// / 0.95;
      ingame.cameraPos.w = ingame.cameraPos.w + 1;// / 1.05;
      ingame.cameraPos.h = ingame.cameraPos.h + 1;// / 1.05;
    }

  Move(t_bunny_position{});
}
