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
  Program		&prog;
  ef::InGame		&ingame;
  
public:
  // t_bunny_response	Loop(void);
  t_bunny_response	Display(void);

  Warfield(Program	&prog,
	   ef::InGame	&ingame);
  ~Warfield(void);
};

#endif	//		__WARFIELD_HPP__
