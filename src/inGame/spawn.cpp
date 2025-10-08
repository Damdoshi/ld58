// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/10/2025 12:30:01 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"inGame.hh"

bool		ef::InGame::spawn(t_bunny_position	pos,
				  const std::string	&type)
{
  if (type.size() < 3)
    return (false);
  if (type[1] != ':')
    return (false);
  if (type[0] == 'u')
    {
      // C'est un peu l'enfer quand meme.
      Bconf bconf{&type[2]};
      auto uconf = std::make_shared<UnitConf>();
      uconf->LoadConf(bconf);
      myUnits.push_back(std::make_shared<Unit>(uconf));
      myUnits.rbegin()->get()->setPos(AcuPos{(double)pos.x, (double)pos.y, 0});
      return (true);
    }
  if (type[0] == 'p')
    {
      return (true);
    }
  return (false);
}
