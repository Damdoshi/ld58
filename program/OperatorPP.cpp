// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:08:22 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Program.hpp"

int			Program::operator()(void)
{
  t_bunny_response	ret;
  size_t		nbr;

  for (nbr = 0; win[nbr]; ++nbr);
  do
    {
      bunny_set_context(contexts[current_context]);
      ret = bunny_loop_mw(win, nbr, freq, (void*)&contexts[current_context]);
    }
  while (ret == GO_ON || ret == SWITCH_CONTEXT);
  return (ret);
}

