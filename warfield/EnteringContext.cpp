// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/10/2025 12:36:34 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"Warfield.hpp"

t_bunny_response	Warfield::EnteringContext(void)
{
  // ingame.spawn({40, 50}, "u:./res/spider.dab");
  // ingame.map.Hit(t_bunny_position{110, 40}, 20, 15, true);
  ingame.map.Hit(t_bunny_position{110, 70}, 20, -15, true);
  // ingame.map.Hit(t_bunny_area{320, 40, 50, 50}, 5, true);
  if (!ingame.music)
    ingame.music = bunny_load_music("./res/theme.ogg");
  if (!bunny_sound_is_playing(&ingame.music->sound))
    bunny_sound_play(&ingame.music->sound);
  return (GO_ON);
}


