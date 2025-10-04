#include "Bpixelarray.hh"

#include <iostream>

void ef::Bpixelarray::placePixel(Pos &pos,
                                 unsigned int colo)
{
  if (pixVec.length > 40000)
    std::cout << "placePixel AHHHHHHH" << std::endl;
  if (px == NULL)
    return;
  if(pos.x >= 0 && pos.x < px->buffer.width && pos.y >= 0 && pos.y < px->buffer.height)
    {
      pixVec.vertex[pixVec.length].pos.x = pos.x;
      pixVec.vertex[pixVec.length].pos.y = pos.y;
      pixVec.vertex[pixVec.length].color = colo;
      pixVec.length += 1;
      //bunny_set_geometry(&px->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&tempV, NULL);
      /*
      t_bunny_color last;
      t_bunny_color color;
      color.full = colo;
      last.full = pixels[pos.x + px->clipable.buffer.width * pos.y];
      if(color.argb[ALPHA_CMP] !=255)
	{
	  double ratio = color.argb[ALPHA_CMP] / 255.0;
	  //std::cout << "placePixel ratio" << ratio << std::endl;
	  color.argb[RED_CMP] = last.argb[RED_CMP] +ratio * (color.argb[RED_CMP]- last.argb[RED_CMP]);
	  color.argb[GREEN_CMP] = last.argb[GREEN_CMP] +ratio * (color.argb[GREEN_CMP]- last.argb[GREEN_CMP]);
	  color.argb[BLUE_CMP] = last.argb[BLUE_CMP] +ratio * (color.argb[BLUE_CMP]- last.argb[BLUE_CMP]);
	  pixels[pos.x + px->clipable.buffer.width * pos.y] = color.full;
	}
      else
	pixels[pos.x + px->clipable.buffer.width * pos.y] = colo;
      */
    }
}
