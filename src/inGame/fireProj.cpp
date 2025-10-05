#include "inGame.hh"

void ef::InGame::fireProj(std::shared_ptr<ProjectileConf> conf,
			  bool isMine)
{
  std::shared_ptr<Projectile> newProj;

  newProj.reset(new Projectile(conf));
  if (isMine)
    myProj.push_back(newProj);
  else
    enemyProj.push_back(newProj);
}
