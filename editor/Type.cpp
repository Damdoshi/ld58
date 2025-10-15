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

t_bunny_response	Editor::Type(uint32_t		chr)
{
  if (focus != buttons["FileName"].font)
    return (GO_ON);
  std::stringstream	ss;

  ss << focus->string;
  ss << chr;
  bunny_free((char*)focus->string);
  focus->string = bunny_strdup(ss.str().c_str());
  bunny_clear(&focus->clipable.buffer, 0);
  bunny_draw(&focus->clipable);
  return (GO_ON);
}

