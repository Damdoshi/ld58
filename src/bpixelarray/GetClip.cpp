#include "Bpixelarray.hh"

t_bunny_clipable *ef::Bpixelarray::GetClip()const
{
  if(px == NULL)
    return NULL;
  return px;
}
