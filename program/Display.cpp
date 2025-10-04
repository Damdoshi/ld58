// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:00:20 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Program.hpp"

void			Program::Display(void)
{
  for (size_t i = 0; win[i]; ++i)
    {
      t_bunny_position	pos;

      screen->scale.x = screen->scale.y = (double)win[i]->buffer.width / screen->buffer.width;
      screen->color_mask.argb[ALPHA_CMP] = 64;
      bunny_blit(&win[i]->buffer, screen, NULL);
      screen->color_mask.argb[ALPHA_CMP] = 255;
      screen->scale.x = screen->scale.y = floor((double)win[i]->buffer.height / screen->buffer.height);
      pos.x = (win[i]->buffer.width - screen->buffer.width * screen->scale.x) / 2;
      pos.y = (win[i]->buffer.height - screen->buffer.height * screen->scale.y) / 2;
      bunny_blit(&win[i]->buffer, screen, &pos);
    }
}
