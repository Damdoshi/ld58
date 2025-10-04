// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:19:28 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	<assert.h>
#include	"MainMenu.hpp"

MainMenu::MainMenu(Program	&program)
  : prog(program)
{
  t_bunny_configuration *nod;
  int		i;
  
  assert((conf = bunny_open_configuration("./res/main_menu.dab", NULL)));
  for (i = 0; bunny_configuration_getf(conf, &nod, "Buttons[%d]", i); ++i)
    {
      const char *str;

      if (bunny_configuration_getf_string(nod, &str, "Action"))
	assert((buttons[str].font = bunny_read_textbox(nod)));
    }

  buttons["Start"].action = &MainMenu::Start;
  buttons["Exit"].action = &MainMenu::Exit;
}

MainMenu::~MainMenu(void)
{
  if (conf)
    bunny_delete_configuration(conf);
}

