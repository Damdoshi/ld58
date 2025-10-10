#include "productor.hh"
#include "Map.hpp"

void ef::Productor::placeResource(Map &map)
{
  if (isPlacing && placingCooldown <= 0 && resources > 0)
    {
      t_bunny_position posi;
      posi.x = pos.x;
      posi.y = pos.y;
      resources += map.Hit(posi, 5, -5, true);
      std::cout << "Productor placeResource resources " << resources << std::endl;
      placingCooldown = 1;
    }
  placingCooldown -= 0.0167;
}

