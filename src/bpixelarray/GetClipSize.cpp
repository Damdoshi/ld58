#include "Bpixelarray.hh"

ef::Pos ef::Bpixelarray::GetClipSize()
{
  Pos pos;

  if(px != NULL)
    {
      pos.x = px->clip_width;
      pos.y = px->clip_height;
    }
  else
    {
      pos.x = -1;
      pos.y = -1;
    }
  return pos;
}
