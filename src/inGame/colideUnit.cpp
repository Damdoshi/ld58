#include "inGame.hh"

/*void ef::InGame::colideUnit(std::shared_ptr<Unit> currUnit)
{
  AcuPos unitPos = currUnit->getPos();
  // colide map
  Pos pos;
  pos.x = (int)(unitPos.x / cellSize.x);
  pos.y = (int)(unitPos.y / cellSize.y);
  //std::cout << "InGame::colideUnit : posx " << (int)(unitPos.x / cellSize.x) << " posy " << (int)(unitPos.y / cellSize.y) << " map " << (int)map[(int)(unitPos.x / cellSize.x) + (int)(unitPos.y / cellSize.y) * map.getMapSize().x] << std::endl;
  if (map[pos.x + pos.y * map.getMapSize().x] != 0)
    {
      double ecartx = unitPos.x - (pos.x * cellSize.x + cellSize.x / 2);
      double ecarty = unitPos.y - (pos.y * cellSize.y + cellSize.y / 2);
      // 4 condition + check si la case a coté est libre
      //std::cout << "InGame::colideUnit : X realPos " << unitPos.x << " treshold " << pos.x * cellSize.x + cellSize.x / 2 << " xcolision" << std::endl;
      //std::cout << "InGame::colideUnit : Y realPos " << unitPos.y << " treshold " << pos.y * cellSize.y + cellSize.y / 2 << std::endl;
      //std::cout << "InGame::colideUnit : cond1 " << (abs(ecartx) > abs(ecarty)) << std::endl;
      if (ecartx < 0 && abs(ecartx) > abs(ecarty))
	{
	  if (map[pos.x - 1 + pos.y * map.getMapSize().x] == 0)
	    unitPos.x = pos.x * cellSize.x;
	  else if (ecarty < 0)
	    unitPos.y = pos.y * cellSize.y;
	  else
	    unitPos.y = pos.y * cellSize.y + cellSize.y;
	}

      if (ecartx > 0 && abs(ecartx) > abs(ecarty))
	{
	  if (map[pos.x + 1 + pos.y * map.getMapSize().x] == 0)
	    unitPos.x = pos.x * cellSize.x + cellSize.x;
	  else if (ecarty < 0)
	    unitPos.y = pos.y * cellSize.y;
	  else
	    unitPos.y = pos.y * cellSize.y + cellSize.y;
	}
      if (ecarty < 0 && abs(ecartx) < abs(ecarty))
	{
	  if (map[pos.x + (pos.y - 1) * map.getMapSize().x] == 0)
	    unitPos.y = pos.y * cellSize.y;
	  else if (ecartx < 0)
	    unitPos.x = pos.x * cellSize.x;
	  else
	    unitPos.x = pos.x * cellSize.x + cellSize.x;
	}
      if (ecarty > 0 && abs(ecartx) < abs(ecarty))
	{
	  if (map[pos.x + (pos.y + 1) * map.getMapSize().x] == 0)
	    unitPos.y = pos.y * cellSize.y + cellSize.y;
	  else if (ecartx < 0)
	    unitPos.x = pos.x * cellSize.x;
	  else
	    unitPos.x = pos.x * cellSize.x + cellSize.x;
	}
      currUnit->setPos(unitPos);
    }

  // colide unit
  for (int i = 0; i < (int)unit.size(); i++)
    if (unit[i]->getId() != currUnit->getId())
      colideUnit(currUnit, unit[i]);
  colideUnit(currUnit, enemy);
  }*/

ef::AcuPos ef::InGame::colideUnit(std::shared_ptr<Unit> currUnit,
				  std::shared_ptr<Unit> otherUnit)
{
  AcuPos unitPos = currUnit->getPos();
  AcuPos otherUnitPos = otherUnit->getPos();
  AcuPos vect(unitPos.x - otherUnitPos.x, unitPos.y - otherUnitPos.y, 0);
  //std::cout << "ingame colideUnit vect " << vect.x << " " << vect.y << std::endl;
  double dist = sqrt(vect.x * vect.x + vect.y * vect.y);
  AcuPos returnVec(0, 0, 0);
  //std::cout << "ingame colideUnit dist " << dist << std::endl;
  if (dist == 0)
    {
      //unitPos.x += 10;
      //unitPos.y += 10;
      //currUnit->setPos(unitPos);
      returnVec.x = 1;
      returnVec.y = 1;
    }
  else if (dist < (otherUnit->getScale().x * 1000) / 2)// + 10 / 2
    {
      double ratio = (1) / dist;
      //unitPos.x = otherUnitPos.x + vect.x * ratio;
      //unitPos.y = otherUnitPos.y + vect.y * ratio;
      returnVec.x = vect.x * ratio;
      returnVec.y = vect.y * ratio;
      //currUnit->setPos(unitPos);
    }
  return returnVec;
}
