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
#include		"StrategicBoard.hpp"

StrategicBoard::StrategicBoard(Program	&p,
			       ef::InGame	&ig)
  : prog(p),
    ingame(ig)
{
  t_bunny_configuration *nod;
  int		i;

  assert((conf = bunny_open_configuration("./res/strategic_board.dab", NULL)));
  for (i = 0; bunny_configuration_getf(conf, &nod, "Buttons[%d]", i); ++i)
    {
      const char *str;

      if (bunny_configuration_getf_string(nod, &str, "Action"))
	assert((buttons[str].font = bunny_read_textbox(nod)));
    }

  buttons["GoWarfield"].action = &StrategicBoard::GoWarfield;
  buttons["StartDig"].action = &StrategicBoard::StartDig;
  buttons["EndDig"].action = &StrategicBoard::EndDig;
  buttons["StartPlace"].action = &StrategicBoard::StartPlace;
  buttons["EndPlace"].action = &StrategicBoard::EndPlace;
  buttons["ResetProd"].action = &StrategicBoard::ResetProd;

  buttons["ProduceSoldier"].action = &StrategicBoard::ProduceSoldier;
  buttons["ProduceTank"].action = &StrategicBoard::ProduceTank;
  buttons["ProduceTurret"].action = &StrategicBoard::ProduceTurret;
  buttons["ProduceProductor"].action = &StrategicBoard::ProduceProductor;
}

StrategicBoard::~StrategicBoard(void)
{
  if (conf)
    bunny_delete_configuration(conf);
}

