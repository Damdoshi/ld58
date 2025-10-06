// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 17:07:11 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Program.hpp"

t_bunny_position	Program::GetMouseRealPosition(t_bunny_position	p) const
{
  t_bunny_position	pos;

  if (p.x < screen->position.x)
    pos.x = 0;
  else if (p.x > screen->position.x + screen->buffer.width * screen->scale.x)
    pos.x = screen->buffer.width - 1;
  else
    pos.x = (p.x - screen->position.x) / screen->scale.x;


  if (p.y < screen->position.y)
    pos.y = 0;
  else if (p.y > screen->position.y + screen->buffer.height * screen->scale.y)
    pos.y = screen->buffer.height - 1;
  else
    pos.y = (p.y - screen->position.y) / screen->scale.y;
  return (pos);
}

t_bunny_position	Program::GetMouseRealPosition(void) const
{
  auto			mp = *bunny_get_mouse_position();

  return (GetMouseRealPosition(mp));
}
