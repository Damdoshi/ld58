// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 19:29:53 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

t_bunny_response	Warfield::Display(void)
{
  std::shared_ptr<ef::Bpixelarray> tempPtr;
  tempPtr.reset(new ef::Bpixelarray(prog.GetScreen()));
  ingame.display(/*std::make_shared<ef::Bpixelarray>(prog.GetScreen())*/ tempPtr, false);
  prog.Display();
  return (GO_ON);
}
