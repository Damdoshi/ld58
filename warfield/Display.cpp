// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:29:53 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

t_bunny_response	Warfield::Display(void)
{
  std::shared_ptr<ef::Bpixelarray> tempPtr;
  tempPtr.reset(new ef::Bpixelarray(prog.GetScreen()));
  ingame.display(tempPtr, false);
  t_bunny_clipable	&screen = prog.GetScreen();

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
