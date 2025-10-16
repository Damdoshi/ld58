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

t_bunny_response	Editor::Click(t_bunny_event_state	state,
				      t_bunny_mouse_button	but)
{
  t_bunny_position	mpos = prog.GetMouseRealPosition();
  t_bunny_configuration	*nod;
  t_bunny_response	ret;

  if (but != BMB_LEFT || state != GO_UP)
    return (GO_ON);
  for (int i = 0; bunny_configuration_getf_node(conf, &nod, "Buttons[%d]", i); ++i)
    {
      const char	*action;

      if (!bunny_configuration_getf_string(nod, &action, "Action"))
	continue ;
      t_bunny_clipable	*clip = (t_bunny_clipable*)buttons[action].font;

      if (!clip)
	continue ;
      if (!buttons[action].action)
	continue ;
      if (mpos.x < clip->position.x || mpos.x > clip->position.x + clip->buffer.width)
	continue ;
      if (mpos.y < clip->position.y || mpos.y > clip->position.y + clip->buffer.height)
	continue ;
      focus = buttons[action].font;
      if ((ret = (this->*buttons[action].action)()) != GO_ON)
	return (ret);
    }
  return (GO_ON);
}

