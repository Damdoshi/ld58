#include "Bpixelarray.hh"

void ef::Bpixelarray::Blit(ef::Bpixelarray &other,
                           AcuPos const &start,
                           AcuPos const &size,
                           float const &rotate)
{
  if(px == NULL || other.px == NULL)
    return;
  AcuPos end;
  end.x = start.x + size.x;
  end.y = start.y + size.y;
  VertexArray<5> tempV;
  tempV.length = 4;
  AcuPos tempMidSize;
  tempMidSize.x = size.x / 2.0;
  tempMidSize.y = size.y / 2.0;
  tempV.vertex[0].pos.x = -tempMidSize.x * cos(rotate) - -tempMidSize.y * sin(rotate);
  tempV.vertex[0].pos.y = -tempMidSize.y * cos(rotate) + -tempMidSize.x * sin(rotate);
  //printf("blit bpixelarray cos %f sin %f posx %f posy %f rotate %f\n", cos(rotate), sin(rotate), tempV.vertex[0].pos.x, tempV.vertex[0].pos.y, rotate);
  tempV.vertex[1].pos.x = tempMidSize.x * cos(rotate) - -tempMidSize.y * sin(rotate);
  tempV.vertex[1].pos.y = -tempMidSize.y * cos(rotate) + tempMidSize.x * sin(rotate);
  tempV.vertex[2].pos.x = tempMidSize.x * cos(rotate) - tempMidSize.y * sin(rotate);
  tempV.vertex[2].pos.y = tempMidSize.y * cos(rotate) + tempMidSize.x * sin(rotate);
  tempV.vertex[3].pos.x = -tempMidSize.x * cos(rotate) - tempMidSize.y * sin(rotate);
  tempV.vertex[3].pos.y = tempMidSize.y * cos(rotate) + -tempMidSize.x * sin(rotate);

  tempV.vertex[0].pos.x += start.x + tempMidSize.x - other.GetClip()->origin.x;
  tempV.vertex[0].pos.y += start.y + tempMidSize.y - other.GetClip()->origin.y;
  tempV.vertex[1].pos.x += end.x - tempMidSize.x - other.GetClip()->origin.x;
  tempV.vertex[1].pos.y += start.y + tempMidSize.y - other.GetClip()->origin.y;
  tempV.vertex[2].pos.x += end.x - tempMidSize.x - other.GetClip()->origin.x;
  tempV.vertex[2].pos.y += end.y - tempMidSize.y - other.GetClip()->origin.y;
  tempV.vertex[3].pos.x += start.x + tempMidSize.x - other.GetClip()->origin.x;
  tempV.vertex[3].pos.y += end.y - tempMidSize.y - other.GetClip()->origin.y;

  tempV.vertex[0].tex.x = 0;
  tempV.vertex[0].tex.y = 0;
  tempV.vertex[1].tex.x = other.GetClipSize().x;
  tempV.vertex[1].tex.y = 0;
  tempV.vertex[2].tex.x = other.GetClipSize().x;
  tempV.vertex[2].tex.y = other.GetClipSize().y;
  tempV.vertex[3].tex.x = 0;
  tempV.vertex[3].tex.y = other.GetClipSize().y;

  bunny_set_geometry(&px->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, other.GetClip());
  //free(tempV.vertex);
  /*
  Pos cursor;

  cursor.x = start.x;
  cursor.y = start.y;
  double xcoef;
  double ycoef;
  while(cursor.x < end.x && cursor.y < end.y)
    {
      xcoef = (double)(cursor.x - start.x)/(double)(end.x - start.x);
      ycoef = (double)(cursor.y - start.y)/(double)(end.y - start.y);

      placePixel(cursor, other.pixels
		 [(int)(xcoef * other.px->clipable.buffer.width) +
		  (int)(ycoef * other.px->clipable.buffer.height) * other.px->clipable.buffer.width]);
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

#include "Bpixelarray.hh"

void ef::Bpixelarray::Blit(ef::Bpixelarray &other,
                           AcuPos const &start,
                           AcuPos const &size)
{
  if(px == NULL || other.px == NULL)
    return;
  AcuPos end;
  end.x = start.x + size.x;
  end.y = start.y + size.y;
  VertexArray<5> tempV;
  tempV.length = 4;
  tempV.vertex[0].pos.x = start.x;// + tempMidSize.x;
  tempV.vertex[0].pos.y = start.y;// + tempMidSize.x;
  tempV.vertex[1].pos.x = end.x;// - tempMidSize.x;
  tempV.vertex[1].pos.y = start.y;// + tempMidSize.y;
  tempV.vertex[2].pos.x = end.x;// - tempMidSize.x;
  tempV.vertex[2].pos.y = end.y;// - tempMidSize.y;
  tempV.vertex[3].pos.x = start.x;// + tempMidSize.x;
  tempV.vertex[3].pos.y = end.y;// - tempMidSize.y;

  tempV.vertex[0].tex.x = 0;
  tempV.vertex[0].tex.y = 0;
  tempV.vertex[1].tex.x = other.GetSize().x;
  tempV.vertex[1].tex.y = 0;
  tempV.vertex[2].tex.x = other.GetSize().x;
  tempV.vertex[2].tex.y = other.GetSize().y;
  tempV.vertex[3].tex.x = 0;
  tempV.vertex[3].tex.y = other.GetSize().y;
  bunny_set_geometry(&px->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, other.GetClip());
  //free(tempV.vertex);
  /*
  Pos cursor;

  cursor.x = start.x;
  cursor.y = start.y;
  double xcoef;
  double ycoef;
  while(cursor.x < end.x && cursor.y < end.y)
    {
      xcoef = (double)(cursor.x - start.x)/(double)(end.x - start.x);
      ycoef = (double)(cursor.y - start.y)/(double)(end.y - start.y);

      placePixel(cursor, other.pixels
		 [(int)(xcoef * other.px->clipable.buffer.width) +
		  (int)(ycoef * other.px->clipable.buffer.height) * other.px->clipable.buffer.width]);
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
