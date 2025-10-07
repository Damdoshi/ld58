// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:45 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: contruc of Bconf

#include "Bconf.hh"

ef::Bconf::Bconf(std::string file)
{
    conf = bunny_open_configuration(&file[0], NULL);
}
