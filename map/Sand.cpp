// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 15:46:56 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"Map.hpp"


// Index local dans le buffer h (Wl = largeur locale du bloc)
#define H(lx, ly) h[(size_t)(lx) + (size_t)(ly) * (size_t)Wl]

void Map::Sand(t_bunny_area area)
{
  // Dimensions GLOBALES de la carte
  const int Wg = size.x;
  const int Hg = size.y;

  // Sous-rectangle (bloc) traité par CE thread
  const int X0 = area.x;
  const int Y0 = area.y;
  const int Wl = area.w;
  const int Hl = area.h;

  // Buffer local (copie des hauteurs du bloc)
  std::vector<int> h;
  h.resize((size_t)Wl * (size_t)Hl);

  // Remplissage depuis la carte globale
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      const int gx = X0 + lx;
      const int gy = Y0 + ly;
      // (optionnel) bornes globales pour SandTop
      if ((unsigned)gx < (unsigned)Wg && (unsigned)gy < (unsigned)Hg)
        H(lx, ly) = SandTop(gx, gy);
    }

  // Voisinage (tu peux garder le tien)
  const int siz = 10;
  t_bunny_position access[siz * siz];
  int acc = 0;

  for (int i = 0; i < siz; ++i)
    for (int j = 0; j < siz; ++j)
      {
	access[acc].x = j - siz / 2;
	access[acc].y = i - siz / 2;
	acc += 1;
      }

  char order[NBRCELL(access) + 1];
  for (int i = 0; i < NBRCELL(access); ++i)
    order[i] = i + 1;
  strfry(order);
  int max = 5;
  order[max] = 0;

  // Simulation locale, mais en vérifiant le type dans la carte GLOBALE
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      const int gx = X0 + lx;
      const int gy = Y0 + ly;

      // stride GLOBAL pour tiles[]
      if (tiles[(size_t)gx + (size_t)gy * (size_t)Wg].type != Tile::SAND)
        continue;

      for (int k = 0; k < max; ++k) {
        const t_bunny_position d = access[order[k] - 1];

        const int ngx = gx + d.x;             // voisin global
        const int ngy = gy + d.y;

        // Remapper en coordonnées LOCALES pour indexer h
        const int nlx = ngx - X0;
        const int nly = ngy - Y0;

        // le buffer local ne couvre que [X0..X0+Wl[, Y0..Y0+Hl[
        if ((unsigned)nlx >= (unsigned)Wl || (unsigned)nly >= (unsigned)Hl)
          continue;

        if (H(lx, ly) - 1 > H(nlx, nly)) {
          H(lx, ly)  -= 1;
          H(nlx, nly) += 1;
        }
      }
    }

  // Écriture retour vers la carte GLOBALE (stride global !)
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      const int gx = X0 + lx, gy = Y0 + ly;
      tiles[(size_t)gx + (size_t)gy * (size_t)Wg].height = H(lx, ly);
    }
}
/*

#define		a(xx, yy) h[(xx) + (yy) * size.x]

void		Map::Sand(t_bunny_area		a)
{
  std::vector<int> h;
  h.resize(size.x * size.y);

  t_bunny_position size = {a.w, a.h};
  t_bunny_position start = {a.x, a.y};
  int		y;
  int		x;

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      h[(x + start.x) + (y + start.y) * size.x] = SandTop(x + start.x, y + start.y);

  t_bunny_position access[] =
    {
     {-1, +0}, {+0, -1}, {+1,  0}, {+0, +1},
     {-1, -1}, {+1, -1}, {+1, +1}, {-1, +1},
     {-2, +0}, {+0, -2}, {+2,  0}, {+0, +2}
    };
  char		str[NBRCELL(access) + 1];
  int		max = NBRCELL(access) + 1;

  max = 2; // Saboté a deux
  int		i;

  for (i = 0; i < max; ++i)
    str[i] = i + 1;
  str[i] = 0;
  strfry(str);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      if (tiles[x + y * size.x].type == Tile::SAND)
	{
	  for (int i = 0; i < max; ++i)
	    {
	      int	tx = access[str[i] - 1].x + x + start.x;
	      int	ty = access[str[i] - 1].y + y + start.y;

	      if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
		continue ;
	      if (a(x + start.x, y + start.y) - 1 > a(tx, ty))
		{
		  a(start.x + x, start.y + y) -= 1;
		  a(tx, ty) += 1;
		}
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      tiles[(x + start.x) + (y + start.y) * size.x].height = a(x + start.x, y + start.y);
}
*/
