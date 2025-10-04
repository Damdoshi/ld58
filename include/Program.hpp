// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 12:10:52 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__PROGRAM_HPP__
# define		__PROGRAM_HPP__
# include		<lapin.h>
# include		<map>

class			Program
{
public:
  enum			Ctx
    {
      SPLASH1,
      SPLASH2,
      MAIN_MENU,
      WARFIELD,
      STRATEGIC_BOARD,
      GAME_OVER,
      CREDITS,
      LAST_CONTEXT,
      INITIAL_CONTEXT	= MAIN_MENU
    };
protected:
  t_bunny_window	**win;
  t_bunny_clipable	*screen;
  t_bunny_configuration	*conf;
  int			freq;

  Ctx			current_context;
  std::map<Ctx, hbs::Context*> contexts;

public:
  int			operator()(void);
  void			Display(void);

  Program(void);
  ~Program(void);
};

#endif	//		__PROGRAM_HPP__
