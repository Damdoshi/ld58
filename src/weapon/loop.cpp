#include "weapons.hh"

void ef::Weapon::loop(AcuPos weaponPos, AcuPos unitPos, double unitRota)
{
  cooldown -= 1;
  if (cooldown < 0)
    cooldown = 0;

  //std::cout << "weapon::loop : target " << target << std::endl;
  if (target.get() != nullptr)
    {
      double dist = sqrt((unitPos.x - target->getPos().x) * (unitPos.x - target->getPos().x) + (unitPos.y - target->getPos().y) * (unitPos.y - target->getPos().y));
      if (dist > range * rangeMul)
	{
	  target = nullptr;
	  return;
	}

      AcuPos posi;
      posi.x = weaponPos.x * cos(unitRota) - weaponPos.y * sin(unitRota);
      posi.y = weaponPos.y * cos(unitRota) + weaponPos.x * sin(unitRota);
      posi = posi + unitPos;
      //std::cout << "weapon::loop : pos x " << getPos().x << " pos y " << getPos().y << " rota " << unitRota << std::endl;
      //std::cout << "weapon::loop : rota pass posi x " << posi.x << " posi y " << posi.y << std::endl;
      AcuPos tempPos(cos(getRota()) * 10, sin(getRota()) * 10, 0);
      AcuPos tempPos2(target->getPos().x - posi.x, target->getPos().y - posi.y, 0);
      double dist1 = tempPos.x * tempPos.x + tempPos.y * tempPos.y;
      double dist2 = tempPos2.x * tempPos2.x + tempPos2.y * tempPos2.y;
      double angle = (tempPos.x * tempPos2.x + tempPos.y * tempPos2.y) / sqrt(dist1 * dist2);

      if (angle > rotaSpeed)
	setRota(getRota() - rotaSpeed);
      else if (angle < -rotaSpeed)
	setRota(getRota() + rotaSpeed);
      else
        setRota(getRota() - angle);

      //setRota(getRota() + 0.001);
    }
  else if ((getRota() - (M_PI * 2) * (int)(getRota() / (M_PI * 2))) >
	   (unitRota - (M_PI * 2) * (int)(unitRota / (M_PI * 2))))
    setRota(getRota() - rotaSpeed);
  else if ((getRota() - (M_PI * 2) * (int)(getRota() / (M_PI * 2))) <
	   (unitRota - (M_PI * 2) * (int)(unitRota / (M_PI * 2))))
    setRota(getRota() + rotaSpeed);
}
