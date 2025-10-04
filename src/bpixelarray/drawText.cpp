// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/05/2024 18:09:27 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "Bpixelarray.hh"

void ef::Bpixelarray::print_char(std::shared_ptr<ef::Bpixelarray> &font,
				 char c,
				 ef::AcuPos &pos)
{
  (void)font;
  AcuPos size(10, 14, 0);
  t_bunny_accurate_position carPos[4];
  t_bunny_position texPos[4];
  carPos[0].x = pos.x;
  carPos[0].y = pos.y;
  texPos[0].x = c * 10;
  texPos[0].y = 0;
  carPos[1].x = pos.x + size.x;
  carPos[1].y = pos.y;
  texPos[1].x = c * 10 + 10;
  texPos[1].y = 0;
  carPos[2].x = pos.x + size.x;
  carPos[2].y = pos.y + size.y;
  texPos[2].x = c * 10 + 10;
  texPos[2].y = 14;
  carPos[3].x = pos.x;
  carPos[3].y = pos.y + size.y;
  texPos[3].x = c * 10;
  texPos[3].y = 14;
  for (int i = 0; i < 4; i += 1)
    {
      textVec.vertex[i + textVec.length].pos = carPos[i];
      textVec.vertex[i + textVec.length].tex = texPos[i];
    }
  textVec.length += 4;

  //bunny_set_geometry(&GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, font->GetClip());
}

void ef::Bpixelarray::drawText(std::shared_ptr<ef::Bpixelarray> &font,
			       std::string str,
			       ef::AcuPos &pos)
{
  int compt;
  int cumul;

  compt = 0;
  cumul = 0;
  while (compt < (int)str.size())
    {
      if (str[compt] == '\n')
        {
	  pos.y += 16;
	  pos.x -= 10 * cumul;
	  cumul = 0;
        }
      else
        {
	  print_char(font, str[compt], pos);
	  cumul += 1;
	  pos.x += 10;
        }
      compt += 1;
    }
}
