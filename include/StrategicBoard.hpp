// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__STRATEGIC_BOARD_HPP__
# define		__STRATEGIC_BOARD_HPP__
# include		<lapin.h>
# include		"Program.hpp"
# include		"inGame.hh"

class			StrategicBoard : public hbs::ContextBridge<StrategicBoard>
{
protected:
  typedef t_bunny_response (StrategicBoard::*Action)(void);
  struct		ButtonProperties
  {
    t_bunny_font	*font;
    StrategicBoard::Action action;
  };

  Program		&prog;
  ef::InGame		&ingame;
  t_bunny_picture	*world_map = NULL;
  t_bunny_picture	*board_decor = NULL;

  t_bunny_configuration	*conf = NULL;
  std::map<std::string, ButtonProperties> buttons;
  t_bunny_response	GoWarfield(void);
  t_bunny_response      ProduceUnit(void);

public:
  t_bunny_response	EnteringContext(void);
  t_bunny_response	Key(t_bunny_event_state		state,
			    t_bunny_keysym		sym);
  t_bunny_response	Loop(void);
  t_bunny_response	Click(t_bunny_event_state	state,
			      t_bunny_mouse_button	but);
  t_bunny_response	Display(void);
  t_bunny_response      Move(const t_bunny_position &rel);


  StrategicBoard(Program	&prog,
		 ef::InGame	&ingame);
  ~StrategicBoard(void);
};

#endif	//		__STRATEGIC_BOARD_HPP__
