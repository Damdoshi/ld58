#include "moveModule.hh"

void ef::MoveModule::addPosToPath(AcuPos newPos)
{
  std::vector<AcuPos> newPath;

  newPath.push_back(newPos);
  for (int i = 0; i < (int)path.size(); i++)
    newPath.push_back(path[i]);
  path = newPath;
}
