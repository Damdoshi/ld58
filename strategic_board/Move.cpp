#include		"StrategicBoard.hpp"

t_bunny_response	StrategicBoard::Move(const t_bunny_position &rel)
{
  (void)rel;
  prog.realmouse = prog.GetMouseRealPosition();
  prog.ingamemouse.x = prog.realmouse.x + prog.ingame.cameraPos.x;
  prog.ingamemouse.y = prog.realmouse.y + prog.ingame.cameraPos.y;


  bunny_set_mouse_visibility(prog.win[0], true);

  ingame.updateSelecting();
  return (GO_ON);
}
