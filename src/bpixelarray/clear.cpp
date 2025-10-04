#include "Bpixelarray.hh"

void ef::Bpixelarray::Clear(unsigned int color)
{
  /*unsigned int max = px->clipable.buffer.width * px->clipable.buffer.height;
    for(unsigned int i = 0; i < max; i++)
    pixels[i] = color;*/
  VertexArray<5> tempV;
  t_bunny_accurate_position pos[4];
  tempV.length = 4;
  //tempV.vertex = new Vertex[5]();
  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = px->buffer.width;
  pos[1].y = 0;
  pos[2].x = px->buffer.width;
  pos[2].y = px->buffer.height;
  pos[3].x = 0;
  pos[3].y = px->buffer.height;
  for (int i = 0; i < 4; i += 1)
    {
      tempV.vertex[i].pos = pos[i];
      tempV.vertex[i].color = color;
    }
  bunny_set_geometry(&px->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, NULL);
  //free(tempV.vertex);
}
