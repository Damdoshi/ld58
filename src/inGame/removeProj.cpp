#include "inGame.hh"

void ef::InGame::removeProj(int index,
			    bool isMine)
{
  std::vector<std::shared_ptr<Projectile>> tempProjList;

  if (isMine)
    {
      for (int i = 0; i < (int)myProj.size(); i++)
	if (i != index)
	  tempProjList.push_back(myProj[i]);
      myProj = tempProjList;
    }
  else
    {
      for (int i = 0; i < (int)enemyProj.size(); i++)
	if (i != index)
	  tempProjList.push_back(enemyProj[i]);
      enemyProj = tempProjList;
    }
}

