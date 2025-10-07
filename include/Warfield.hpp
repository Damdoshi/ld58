// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__WARFIELD_HPP__
# define		__WARFIELD_HPP__
# include		<lapin.h>
# include		"Program.hpp"
# include		"inGame.hh"

class			Warfield : public hbs::ContextBridge<Warfield>
{
protected:
  typedef t_bunny_response (Warfield::*Action)(void);
  struct		ButtonProperties
  {
    t_bunny_font	*font;
    Warfield::Action action;
  };

  Program		&prog;
  ef::InGame		&ingame;
  void			KeyCamera(void);

  t_bunny_configuration	*conf;
  std::map<std::string, ButtonProperties> buttons;
  t_bunny_response	GoStrategic(void);

public:
  t_bunny_response	EnteringContext(void);

  t_bunny_response	Loop(void);
  t_bunny_response	Key(t_bunny_event_state		state,
			    t_bunny_keysym		sym);
  t_bunny_response	Click(t_bunny_event_state	state,
			      t_bunny_mouse_button	but);
  t_bunny_response	Move(const t_bunny_position	&rel);

  // t_bunny_response	Loop(void);
  t_bunny_response	Display(void);

  Warfield(Program	&prog,
	   ef::InGame	&ingame);
  ~Warfield(void);
};

#endif	//		__WARFIELD_HPP__
