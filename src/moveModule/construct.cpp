#include "moveModule.hh"

ef::MoveModule::MoveModule(std::shared_ptr<MoveModuleConf> conf)
  :
  speed(conf->speed),
  rotaSpeed(conf->rotaSpeed),
  nextPosition(-1, -1, -1),
  maxDivergeance(conf->maxDivergeance)
{}

