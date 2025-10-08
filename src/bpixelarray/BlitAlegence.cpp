#include "Bpixelarray.hh"
#include <map>
void ef::Bpixelarray::Blit(ef::Bpixelarray &other,
                           Pos const &start,
                           AcuPos const &size,
			   int alegence/*,
                           float const rotate*/)
{
  if(px == NULL || other.px == NULL)
    return;

  t_bunny_color colo;
  colo.full = (alegence + 24) * (alegence + 42) * 10000 + (alegence + 69) * (alegence + 34);
  colo.argb[RED_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  colo.argb[GREEN_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  colo.argb[BLUE_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  colo.argb[ALPHA_CMP] = 255;

  Pos end;
  end.x = start.x + size.x;
  end.y = start.y + size.y;
  VertexArray<5> tempV;
  //tempV.vertex = new Vertex[5]();
  tempV.length = 4;
  tempV.vertex[0].pos.x = start.x;
  tempV.vertex[0].pos.y = start.y;
  tempV.vertex[0].tex.x = 0;
  tempV.vertex[0].tex.y = 0;
  tempV.vertex[0].color = colo.full;
  tempV.vertex[1].pos.x = end.x;
  tempV.vertex[1].pos.y = start.y;
  tempV.vertex[1].tex.x = other.GetSize().x;
  tempV.vertex[1].tex.y = 0;
  tempV.vertex[1].color = colo.full;
  tempV.vertex[2].pos.x = end.x;
  tempV.vertex[2].pos.y = end.y;
  tempV.vertex[2].tex.x = other.GetSize().x;
  tempV.vertex[2].tex.y = other.GetSize().y;
  tempV.vertex[2].color = colo.full;
  tempV.vertex[3].pos.x = start.x;
  tempV.vertex[3].pos.y = end.y;
  tempV.vertex[3].tex.x = 0;
  tempV.vertex[3].tex.y = other.GetSize().y;
  tempV.vertex[3].color = colo.full;
  tempV.vertex[4].pos.x = start.x;
  tempV.vertex[4].pos.y = start.y;
  tempV.vertex[4].tex.x = 0;
  tempV.vertex[4].tex.y = 0;
  tempV.vertex[4].color = colo.full;
  bunny_set_geometry(&px->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, other.GetClip());
  tempV.length = 5;
  bunny_set_geometry(&px->buffer, BGY_LINE_STRIP, (t_bunny_vertex_array *)&tempV, NULL);
  tempV.vertex[0].pos.x = start.x + 1;
  tempV.vertex[0].pos.y = start.y + 1;
  tempV.vertex[1].pos.x = end.x - 1;
  tempV.vertex[1].pos.y = start.y + 1;
  tempV.vertex[2].pos.x = end.x - 1;
  tempV.vertex[2].pos.y = end.y - 1;
  tempV.vertex[3].pos.x = start.x + 1;
  tempV.vertex[3].pos.y = end.y - 1;
  tempV.vertex[4].pos.x = start.x + 1;
  tempV.vertex[4].pos.y = start.y + 1;
  bunny_set_geometry(&px->buffer, BGY_LINE_STRIP, (t_bunny_vertex_array *)&tempV, NULL);
  //free(tempV.vertex);
  /*
  std::map<int, bool> gate;
	    Pos end;

  end.x = start.x + size.x;
  end.y = start.y + size.y;

  Pos cursor;

  cursor.x = start.x;
  cursor.y = start.y;
  double xcoef;
  double ycoef;
  unsigned int color;
  while(cursor.x < end.x && cursor.y < end.y)
    {
      xcoef = (double)(cursor.x - start.x)/(double)(end.x - start.x);
      ycoef = (double)(cursor.y - start.y)/(double)(end.y - start.y);
      color = other.pixels[(int)(xcoef * other.px->clipable.buffer.width) +
	 (int)(ycoef * other.px->clipable.buffer.height) * other.px->clipable.buffer.width];
      if(gate.count(color) == 0)
	{
	  gate[color] = true;
	}
      if(color == 4289069221)
	placePixel(cursor, colo.full);
      else
	if(color != 4294902015)
	  placePixel(cursor, color);
      if(cursor.x == end.x-1)
	{
	  cursor.x = start.x;
	  cursor.y ++;
	}
      else
	cursor.x ++;
    }
  */
}
