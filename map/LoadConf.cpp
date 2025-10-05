// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 18:06:56 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Map.hpp"

bool		Map::LoadConf(ef::Bconf		&conf)
{
  t_bunny_configuration *cnf = conf.Get();
  const char	*str;
  t_bunny_pixelarray *material;
  t_bunny_pixelarray *height;
  t_bunny_pixelarray *water;
  bool		ret = false;

  if (!bunny_configuration_getf_string(cnf, &str, "MaterialMap"))
    return (false);
  if ((material = bunny_load_pixelarray(str)) == NULL)
    return (false);

  if (!bunny_configuration_getf_string(cnf, &str, "HeightMap"))
    goto Delete_Material;
  if ((height = bunny_load_pixelarray(str)) == NULL)
    goto Delete_Material;

  if (!bunny_configuration_getf_string(cnf, &str, "WaterMap"))
    goto Delete_Height;
  if ((water = bunny_load_pixelarray(str)) == NULL)
    goto Delete_Height;

  if (water->clipable.buffer.width != height->clipable.buffer.width
      || water->clipable.buffer.width != material->clipable.buffer.width)
    goto Delete_Water;
  if (water->clipable.buffer.height != height->clipable.buffer.height
      || water->clipable.buffer.height != material->clipable.buffer.height)
    goto Delete_Water;

  tiles.resize(water->clipable.buffer.width * water->clipable.buffer.height);
  waters.resize(water->clipable.buffer.width * water->clipable.buffer.height);
  size.x = water->clipable.buffer.width;
  size.y = water->clipable.buffer.height;

  for (int i = 0; i < size.x * size.y; ++i)
    {
      tiles[i].SetTile(((unsigned int*)material->pixels)[i],
		       ((unsigned int*)height->pixels)[i] & ~BLACK);
      tiles[i].SetPos(i % size.x, i / size.x);
      waters[i].SetTile(BLUE, ((unsigned int*)water->pixels)[i] & ~BLACK);
      waters[i].SetPos(i % size.x, i / size.x);
    }

  ret = true;

 Delete_Water:
  bunny_delete_clipable(&water->clipable);
 Delete_Height:
  bunny_delete_clipable(&height->clipable);
 Delete_Material:
  bunny_delete_clipable(&material->clipable);
  return (ret);
}

bool		Map::LoadConf(const std::string	&conf)
{
  ef::Bconf	cnf(conf);

  if (!cnf.Get())
    return (false);
  return (LoadConf(cnf));
}

