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
  Program		&prog;
  ef::InGame		&ingame;
  
public:
  // t_bunny_response	Loop(void);
  t_bunny_response	Display(void);

  StrategicBoard(Program	&prog,
		 ef::InGame	&ingame);
  ~StrategicBoard(void);
};

#endif	//		__STRATEGIC_BOARD_HPP__
