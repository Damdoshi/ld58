// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:54 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: getter of conf

#include "Bconf.hh"

t_bunny_configuration *ef::Bconf::Get()
{
    return conf;
}
