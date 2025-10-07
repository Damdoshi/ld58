// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:29:03 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		<assert.h>
#include		"Warfield.hpp"

Warfield::Warfield(Program	&p,
		   ef::InGame	&ig)
  : prog(p),
    ingame(ig)
{
  t_bunny_configuration *nod;
  int		i;

  assert((conf = bunny_open_configuration("./res/warfield.dab", NULL)));
  for (i = 0; bunny_configuration_getf(conf, &nod, "Buttons[%d]", i); ++i)
    {
      const char *str;

      if (bunny_configuration_getf_string(nod, &str, "Action"))
	assert((buttons[str].font = bunny_read_textbox(nod)));
    }
  buttons["GoStrategic"].action = &Warfield::GoStrategic;
}

Warfield::~Warfield(void)
{
  if (conf)
    bunny_delete_configuration(conf);
}

