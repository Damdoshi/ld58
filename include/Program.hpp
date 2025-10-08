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
# include		"inGame.hh"

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
      INITIAL_CONTEXT	= WARFIELD
    };
protected:
public: // fuque
  t_bunny_window	**win;
  t_bunny_clipable	*screen;
  t_bunny_configuration	*conf;
  t_bunny_threadpool	*pool;
  int			freq;

  Ctx			current_context;
  std::map<Ctx, hbs::Context*> contexts;

  ef::InGame		ingame;

  t_bunny_position	realmouse;
  t_bunny_position	ingamemouse;

public:
  t_bunny_position	GetMouseRealPosition(t_bunny_position	p) const;
  t_bunny_position	GetMouseRealPosition(void) const;
  void			SetContext(Ctx				ctx);
  t_bunny_clipable	&GetScreen(void);
  int			operator()(void);
  void			Display(void);

  Program(void);
  ~Program(void);
};

extern Program		*gprog;

#endif	//		__PROGRAM_HPP__
