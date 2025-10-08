#include "inGame.hh"
#include "Program.hpp"

void ef::InGame::fireGun()
{
  if (hero.get() != nullptr)
    {
      std::shared_ptr<ProjectileConf> tempProj = hero->getWeapon()->manualShoot();
      if (tempProj.get() != nullptr)
	{
	  std::shared_ptr<Projectile> newProj;

	  newProj.reset(new Projectile(tempProj));
	  t_bunny_position mousePos = prog.ingamemouse;
	  AcuPos target(mousePos.x,
			mousePos.y - 150, 0);
	  newProj->setDestination(target);
	  newProj->setPos(hero->getPos());
	  myProj.push_back(newProj);
	}
    }
}
