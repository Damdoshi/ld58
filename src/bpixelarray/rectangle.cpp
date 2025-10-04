// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/04/2024 17:21:07 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "Bpixelarray.hh"

void ef::Bpixelarray::rectangle(ef::AcuPos &start,
				ef::AcuPos &size,
				unsigned int background,
				unsigned int outline)
{
  (void)outline;
  t_bunny_accurate_position pos[4];
  pos[0].x = start.x;
  pos[0].y = start.y;
  pos[1].x = start.x + size.x;
  pos[1].y = start.y;
  pos[2].x = start.x + size.x;
  pos[2].y = start.y + size.y;
  pos[3].x = start.x;
  pos[3].y = start.y + size.y;
  for (int i = 0; i < 4; i += 1)
    {
      recVec.vertex[i + recVec.length].pos = pos[i];
      recVec.vertex[i + recVec.length].color = background;
    }
  recVec.length += 4;
  //bunny_set_geometry(&px->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, NULL);
  //bunny_set_geometry(&px->buffer, BGY_LINE_STRIP, (t_bunny_vertex_array *)&tempV, NULL);
  /*
  Pos pos;
  pos.x = start.x;
  pos.y = start.y;

  while(pos.x + px->clipable.buffer.width * pos.y < start.x + size.x + px->clipable.buffer.width * (start.y + size.y))
    {
      //if(pos.x >= 0 && pos.y >= 0 && pos.x < px->clipable.buffer.width && pos.y < px->clipable.buffer.height)
      //pixels[pos.x + pos.y * px->clipable.buffer.width] = (pos.x == start.x || pos.x == (start.x + size.x) || pos.y == start.y || pos.y == (start.y + size.y - 1)) ? outline : background;
      placePixel(pos, (pos.x == start.x || pos.x == (start.x + size.x) || pos.y == start.y || pos.y == (start.y + size.y - 1)) ? outline : background);
      if(pos.x >= start.x + size.x)
	{
	  pos.x = start.x;
	  pos.y ++;
	}
      else
	pos.x ++;
    }
  */
}
