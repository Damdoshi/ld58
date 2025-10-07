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
  //bunny_clear(&screen->buffer, RED);

  for (size_t i = 0; win[i]; ++i)
    {
      bunny_clear(&win[i]->buffer, ALPHA(64, BLACK));

      screen->scale.x = screen->scale.y = (double)win[i]->buffer.width / screen->buffer.width;
      screen->color_mask.argb[ALPHA_CMP] = 64;
      screen->position.x = 0;
      screen->position.y = (win[i]->buffer.height - (screen->buffer.height * screen->scale.y)) / 2;
      bunny_blit(&win[i]->buffer, screen, NULL);

      screen->color_mask.argb[ALPHA_CMP] = 255;
      screen->scale.x = screen->scale.y = floor((double)win[i]->buffer.height / screen->buffer.height);
      screen->position.x = (win[i]->buffer.width - screen->buffer.width * screen->scale.x) / 2;
      screen->position.y = (win[i]->buffer.height - screen->buffer.height * screen->scale.y) / 2;
      bunny_blit(&win[i]->buffer, screen, NULL);
      bunny_display(win[i]);
    }
}

