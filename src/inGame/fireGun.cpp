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
	  AcuPos target(mousePos.x/* - cameraPos.x*/,
			mousePos.y/* - cameraPos.y*/, 0);
	  newProj->setDestination(target);
	  std::cout << "fireProj targetPos.x " << target.x << " y " << target.y << std::endl;
	  newProj->setPos(hero->getPos());
	  myProj.push_back(newProj);
	}
    }
}
