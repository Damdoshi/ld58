// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/10/2025 15:46:56 ******************************************************
// damdoshi <damdoshi@terechkova.efrits.fr>
// -  -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	<algorithm>
#include	"Map.hpp"


// Index local dans les buffers h (terrain/top) et w (eau) du bloc
#define H(lx, ly) h[(size_t)(lx) + (size_t)(ly) * (size_t)Wl]
#define W(lx, ly) w[(size_t)(lx) + (size_t)(ly) * (size_t)Wl]

void Map::Water(t_bunny_area area, int phase4)
{
  // Clamp du paramètre (0..3)
  phase4 &= 3;

  // Dimensions GLOBALES
  const int Wg = size.x;
  const int Hg = size.y;

  // Bloc local
  const int X0 = area.x;
  const int Y0 = area.y;
  const int Wl = area.w;
  const int Hl = area.h;

  if (Wg <= 0 || Hg <= 0 || Wl <= 0 || Hl <= 0) return;

  // Buffers locaux
  std::vector<int> h; h.resize((size_t)Wl * (size_t)Hl); // “hauteur de référence” (sol/top)
  std::vector<int> w; w.resize((size_t)Wl * (size_t)Hl); // volume d’eau

  // --- Import depuis la carte GLOBALE ---
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      const int gx = X0 + lx;
      const int gy = Y0 + ly;
      if (gx >= 0 && gy >= 0 && gx < Wg && gy < Hg) {
        H(lx, ly) = WaterTop(gx, gy);
        W(lx, ly) = waters[(size_t)gx + (size_t)gy * (size_t)Wg].height;
      } else {
        H(lx, ly) = 0;
        W(lx, ly) = 0;
      }
    }

  // Voisins (biais gravité: bas, gauche, droite, haut)
  const t_bunny_position neigh[4] = { {0, +1}, {-1, 0}, {+1, 0}, {0, -1} };

  // Paramètres de diffusion
  constexpr int THRESH        = 2; // pente minimale (frein)
  constexpr int FLOW_CAP_SRC  = 2; // max unités qu'une cellule émet / frame
  constexpr int FLOW_CAP_NEI  = 1; // max vers un voisin / frame

  // Double buffer
  std::vector<int> w_next = w;

  // --- Simulation locale (ne traite qu'1 pixel / 2x2 selon phase4) ---
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      // Sélection du sous-échantillonnage 2x2
      const int code = (lx & 1) | ((ly & 1) << 1);
      if (code != phase4) continue;

      if (W(lx, ly) <= 0) continue;

      // ordre aléatoire par cellule (chaîne terminée pour strfry)
      char order[5] = {1, 2, 3, 4, 0};
      strfry(order);

      int src_budget = FLOW_CAP_SRC;
      const int Psrc = H(lx, ly) + W(lx, ly);

      for (int oi = 0; order[oi] && src_budget > 0; ++oi) {
        const t_bunny_position d = neigh[(int)order[oi] - 1];

        const int nlx = lx + d.x;
        const int nly = ly + d.y;
        if ((unsigned)nlx >= (unsigned)Wl || (unsigned)nly >= (unsigned)Hl)
          continue;

        const int Pdst = H(nlx, nly) + W(nlx, nly); // décision sur état courant
        const int dP   = Psrc - Pdst;

        if (dP >= THRESH && W(lx, ly) > 0) {
          const int give = std::min({FLOW_CAP_NEI, src_budget, W(lx, ly)});
          w_next[(size_t)lx  + (size_t)ly  * (size_t)Wl] -= give;
          w_next[(size_t)nlx + (size_t)nly * (size_t)Wl] += give;
          src_budget -= give;
        }
      }
    }

  // Commit
  w.swap(w_next);

  // --- Export vers la carte GLOBALE (stride global) ---
  for (int ly = 0; ly < Hl; ++ly)
    for (int lx = 0; lx < Wl; ++lx) {
      const int gx = X0 + lx, gy = Y0 + ly;
      if (gx >= 0 && gy >= 0 && gx < Wg && gy < Hg)
        waters[(size_t)gx + (size_t)gy * (size_t)Wg].height = W(lx, ly);
    }
}




/*


#define		a(xx, yy) h[(xx) + (yy) * size.x]

void		Map::Water(t_bunny_area		a)
{
  std::vector<int> h;
  std::vector<int> w;

  h.resize(size.x * size.y);
  w.resize(size.x * size.y);
  t_bunny_position size = {a.w, a.h};
  t_bunny_position start = {a.x, a.y};
  int		y;
  int		x;

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      {
	h[x + start.x + (y + start.y) * size.x] = WaterTop(x + start.x, y + start.y);
	w[x + start.x + (y + start.y) * size.x] = waters[x + start.x + (y + start.y) * size.x].height;
      }

  t_bunny_position access[4] =
    {
     {-1,  0},
     { 0, -1},
     {+1,  0},
     { 0, +1}
    };
  char		str[5] = {1, 2, 3, 4};

  strfry(str);
  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      for (int i = 0; i < 4 && w[y * size.x + x] > 0; ++i)
	{
	  int	tx = access[str[i] - 1].x + x + start.x;
	  int	ty = access[str[i] - 1].y + y + start.y;

	  if (tx < 0 || ty < 0 || tx >= size.x || ty >= size.y)
	    continue ;
	  for (int mx = 0; mx < 3 && (a(x + start.x, y + start.y) > a(tx, ty)) && w[x + start.x + (y + start.y) * size.x] > 0; ++mx)
	    {
	      a(x + start.x, y + start.y) -= 1;
	      a(tx, ty) += 1;
	      w[x + start.x + + (y + start.y) * size.x] -= 1;
	      w[tx + ty * size.x] += 1;
	    }
	}

  for (y = 0; y < size.y; ++y)
    for (x = 0; x < size.x; ++x)
      waters[x + start.x + (y + start.y) * size.x].height = w[x + start.x + (y + start.y) * size.x];
}

*/
