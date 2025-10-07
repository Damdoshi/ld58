// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:46 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: retry the init of conf

#include "Bconf.hh"

bool ef::Bconf::retry(std::string file)
{
    return ((conf = bunny_open_configuration(&file[0], NULL)) == NULL)? true : false;
}
