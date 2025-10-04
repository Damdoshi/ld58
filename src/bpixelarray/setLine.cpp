#include "Bpixelarray.hh"

void ef::Bpixelarray::setLine(ef::AcuPos &start,
			      ef::AcuPos &end,
			      unsigned int color)
{
  t_bunny_accurate_position pos[2];

  pos[0].x = start.x;
  pos[0].y = start.y;
  pos[1].x = end.x;
  pos[1].y = end.y;

  lineVec.vertex[lineVec.length].pos = pos[0];
  lineVec.vertex[lineVec.length].color = color;
  lineVec.vertex[lineVec.length + 1].pos = pos[1];
  lineVec.vertex[lineVec.length + 1].color = color;
  lineVec.length += 2;
}
