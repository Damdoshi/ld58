#include "inGame.hh"

void ef::InGame::removeProj(int index,
			    bool isMine)
{
  std::vector<std::shared_ptr<Projectile>> tempProjList;

  std::cout << "removeProj boom" << std::endl;
  if (isMine)
    {
      for (int i = 0; i < (int)myProj.size(); i++)
	{
	  if (i != index)
	    tempProjList.push_back(myProj[i]);
	  else if (myProj[i]->getProjType() == ARC)
	    {
	      t_bunny_position posi;
	      posi.x = myProj[i]->getPos().x;
	      posi.y = myProj[i]->getPos().y;
	      map.Hit(posi, myProj[i]->getRadius(), myProj[i]->getRadius(), true);
	    }
	}
      myProj = tempProjList;
    }
  else
    {
      for (int i = 0; i < (int)enemyProj.size(); i++)
	{
	  if (i != index)
	    tempProjList.push_back(enemyProj[i]);
	  else if (enemyProj[i]->getProjType() == ARC)
	    {
	      t_bunny_position posi;
	      posi.x = enemyProj[i]->getPos().x;
	      posi.y = enemyProj[i]->getPos().y;
	      map.Hit(posi, enemyProj[i]->getRadius(), enemyProj[i]->getRadius(), true);
	    }
	}
      enemyProj = tempProjList;
    }
}

