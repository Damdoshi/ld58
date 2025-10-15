// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:27:05 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__EDITOR_HPP__
# define		__EDITOR_HPP__
# include		<lapin.h>
# include		"Program.hpp"
# include		"inGame.hh"

class			Editor : public hbs::ContextBridge<Editor>
{
protected:
  typedef t_bunny_response (Editor::*Action)(void);
  struct		ButtonProperties
  {
    t_bunny_font	*font;
    Editor::Action	action;
  };

  Program		&prog;
  ef::InGame		&ingame;

  t_bunny_configuration	*conf = NULL;
  std::map<std::string, ButtonProperties> buttons;

  t_bunny_font		*focus;

#define X(a) t_bunny_response a(void)
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
#undef X

public:
  bool			LoadMap(const std::string	&name);
  bool			SaveMap(const std::string	&name);
  t_bunny_response	Type(uint32_t			unicode);

  t_bunny_response	Key(t_bunny_event_state		state,
			    t_bunny_keysym		sym);
  t_bunny_response	Loop(void);
  t_bunny_response	Click(t_bunny_event_state	state,
			      t_bunny_mouse_button	but);
  t_bunny_response	Display(void);

  Editor(Program	&prog,
	 ef::InGame	&ingame);
  ~Editor(void);
};

#endif	//		__EDITOR_HPP__
