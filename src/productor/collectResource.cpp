#include "productor.hh"
#include "Map.hpp"

void ef::Productor::collectResource(Map &map)
{
  if (isCollecting && collectCooldown <= 0)
    {
      t_bunny_position posi;
      posi.x = pos.x;
      posi.y = pos.y;
      resources += map.Hit(posi, 5, 5, true);
      std::cout << "Productor collectResource resources " << resources << std::endl;
      collectCooldown = 1;
    }
  collectCooldown -= 0.0167;
}
