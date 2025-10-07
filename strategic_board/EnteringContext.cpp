// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/10/2025 16:33:28 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		<assert.h>
#include		"StrategicBoard.hpp"

t_bunny_response	StrategicBoard::EnteringContext(void)
{
  if (!world_map)
    {
      assert((world_map = bunny_new_picture(prog.GetScreen().buffer.width * 0.75, prog.GetScreen().buffer.height * 0.75)));
      world_map->position.x = (prog.GetScreen().buffer.width - world_map->buffer.width) / 2;
      world_map->position.y = (prog.GetScreen().buffer.height - world_map->buffer.height) / 2;
    }
  if (!board_decor)
    {
      assert((board_decor = bunny_load_picture("./res/strategic_board.dab")));
      board_decor->scale.x = (double)prog.GetScreen().buffer.width / board_decor->buffer.width;
      board_decor->scale.y = (double)prog.GetScreen().buffer.height / board_decor->buffer.height;
    }

  if (!ingame.music)
    ingame.music = bunny_load_music("./res/theme.ogg");
  if (!bunny_sound_is_playing(&ingame.music->sound))
    bunny_sound_play(&ingame.music);
  return (GO_ON);
}
