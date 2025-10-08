// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 13:17:17 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__MAIN_MENU_HPP__
# define		__MAIN_MENU_HPP__
# include		<lapin.h>
# include		<map>

class			Program;
class			MainMenu : public hbs::ContextBridge<MainMenu>
{
protected:
  typedef t_bunny_response (MainMenu::*Action)(void);
  struct		ButtonProperties
  {
    t_bunny_font	*font;
    MainMenu::Action	action;
  };
  Program		&prog;

  std::map<std::string, ButtonProperties> buttons;
  t_bunny_response	Start(void);
  t_bunny_response	Exit(void);

  t_bunny_configuration	*conf;

public:
  t_bunny_response	Click(t_bunny_event_state	state,
			      t_bunny_mouse_button	but);
  t_bunny_response	Display(void);

  MainMenu(Program	&prog);
  ~MainMenu(void);
};

#endif	//		__MAIN_MENU_HPP__
