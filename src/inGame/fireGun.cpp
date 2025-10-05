#include "inGame.hh"

void ef::InGame::fireGun()
{
  if (hero.get() != nullptr)
    {
      std::shared_ptr<ProjectileConf> tempProj = hero->shoot();
      if (tempProj.get() != nullptr)
	fireProj(tempProj, true);
    }
}
