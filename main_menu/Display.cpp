// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 15:59:26 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Program.hpp"
#include		"MainMenu.hpp"

t_bunny_response	MainMenu::Display(void)
{
  t_bunny_clipable	&screen = prog.GetScreen();

  bunny_clear(&screen.buffer, RED);
  for (auto it = buttons.begin(); it != buttons.end(); ++it)
    if (it->second.font)
      {
	bunny_clear(&it->second.font->clipable.buffer, BLACK);
	bunny_draw(&it->second.font->clipable);
	bunny_blit(&screen.buffer, &it->second.font->clipable, NULL);
      }
  prog.Display();
  return (GO_ON);
}

