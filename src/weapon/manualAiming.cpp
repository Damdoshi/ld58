#include "weapons.hh"

void ef::Weapon::manualAiming(AcuPos weaponPos,
			      AcuPos unitPos,
			      double unitRota,
			      AcuPos targetPos)
{
  //std::cout << "weapon::loop : target " << target << std::endl;
  //std::cout << "weapon manualAiming targetPos " << targetPos.x << " " << targetPos.y << std::endl;
  unitRota = 0;
  if (isManual)
    {
      AcuPos posi;
      posi.x = weaponPos.x * cos(unitRota) - weaponPos.y * sin(unitRota);
      posi.y = weaponPos.y * cos(unitRota) + weaponPos.x * sin(unitRota);
      posi = posi + unitPos;
      //std::cout << "weapon::loop : pos x " << getPos().x << " pos y " << getPos().y << " rota " << unitRota << std::endl;
      //std::cout << "weapon::loop : rota pass posi x " << posi.x << " posi y " << posi.y << std::endl;
      AcuPos tempPos(cos(getRota()) * 10, sin(getRota()) * 10, 0);
      AcuPos tempPos2(targetPos.x - posi.x, targetPos.y - posi.y, 0);
      double dist1 = tempPos.x * tempPos.x + tempPos.y * tempPos.y;
      double dist2 = tempPos2.x * tempPos2.x + tempPos2.y * tempPos2.y;
      double angle = (tempPos.x * tempPos2.x + tempPos.y * tempPos2.y) / sqrt(dist1 * dist2);

      //std::cout << "weapon manualAiming before rota " << getRota() << " angle " << angle << std::endl;
      if (angle > rotaSpeed)
	{
	  //std::cout << "weapon manualAiming minus rota " << std::endl;
	  setRota(getRota() - rotaSpeed);
	}
      else if (angle < -rotaSpeed)
	{
	  //std::cout << "weapon manualAiming plus rota " << std::endl;
	  setRota(getRota() + rotaSpeed);
	}
      else
	{
	  //std::cout << "weapon manualAiming set angle rota " << std::endl;
	  setRota(getRota() - angle);
	}
      //std::cout << "weapon manualAiming after rota " << getRota() << " rotaSpeed " << rotaSpeed << std::endl;

      //setRota(getRota() + 0.001);
    }
}
