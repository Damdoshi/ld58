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

t_bunny_response	Editor::Key(t_bunny_event_state	state,
				    t_bunny_keysym	sym)
{
  if (state != GO_DOWN)
    return (GO_ON);
  if (sym == BKS_BACKSPACE)
    {
      if (focus != buttons["FileName"].font)
	return (GO_ON);
      int		len;

      if ((len = strlen(focus->string)) != 0)
	((char*)focus->string)[len - 1] = 0;
      return (GO_ON);
    }
  return (GO_ON);
}
