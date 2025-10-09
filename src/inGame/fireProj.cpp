#include "inGame.hh"

void ef::InGame::fireProj(std::shared_ptr<ProjectileConf> conf,
			  bool isMine,
			  std::shared_ptr<Unit> unit)
{
  std::shared_ptr<Projectile> newProj;

  newProj.reset(new Projectile(conf));
  newProj->setDestination(unit->getWeapon()->getTarget()->getPos());
  //std::cout << "fireProj targetPos.x " << unit->getWeapon()->getTarget()->getPos().x << " y " << unit->getWeapon()->getTarget()->getPos().y << " isMine " << isMine << std::endl;
  newProj->setPos(unit->getPos());
  newProj->setRota(unit->getWeapon()->getRota());
  if (isMine)
    myProj.push_back(newProj);
  else
    enemyProj.push_back(newProj);
}
