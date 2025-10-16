// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include			<assert.h>
#include			"Editor.hpp"

Editor::Editor(Program		&_prog,
	       ef::InGame	&_ingame)
  : prog(_prog),
    ingame(_ingame)
{
  t_bunny_configuration *nod;
  int		i;

  assert((conf = bunny_open_configuration("./res/editor.dab", NULL)));
  for (i = 0; bunny_configuration_getf(conf, &nod, "Buttons[%d]", i); ++i)
    {
      const char *str;

      if (bunny_configuration_getf_string(nod, &str, "Action"))
	assert((buttons[str].font = bunny_read_textbox(nod)));
    }
#define X(a) buttons[#a].action = &Editor::a
  X(LargerBrush);
  X(SmallerBrush);
  X(RoundBrush);
  X(SquareBrush);
  X(AddBrush);
  X(RemoveBrush);
  X(EqualizeBrush);
  X(RockLayer);
  X(SandLayer);
  X(WaterLayer);
  X(Load);
  X(Save);
  X(FileName);
  X(Simulate);
}

Editor::~Editor(void)
{}

