// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:59 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: to check if conf is corectly open

#include "Bconf.hh"

bool ef::Bconf::operator()()
{
    return (conf == NULL)? true: false;
}
