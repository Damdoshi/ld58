// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 22/04/2024 15:50:27 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __BPIXELARRAY_HH__
#define __BPIXELARRAY_HH__

#include <string>
#include <memory>
#include <lapin.h>
#include <iostream>

namespace ef
{
  struct Pos
  {
    Pos(){}
    Pos(int both);
    Pos(int newx, int newy)
      :
      x(newx),
      y(newy)
    {};
    Pos(Pos const &other);
    Pos &operator=(Pos const& other);
    int isInRange(Pos other, int _x, int _y);

    int x;
    int y;
  };

  struct AcuPos
  {
    AcuPos() = default;
    AcuPos(double newx, double newy, double newz) :
      x(newx), y(newy), z(newz)
    {};
    AcuPos operator+(AcuPos const& other)
    {
      AcuPos newPos;
      newPos.x = x + other.x;
      newPos.y = y + other.y;
      return newPos;
    };


    double x;
    double y;
    double z;
  };

  struct Vertex
  {
    t_bunny_accurate_position pos;
    t_bunny_position tex;
    unsigned int color;
  };

  template <int Len>
  struct VertexArray
  {
    size_t length;
    Vertex vertex[Len];
  };


  class Bpixelarray
  {
  public:
    Bpixelarray(t_bunny_picture &pic);
    Bpixelarray(const Bpixelarray &) = delete;
    Bpixelarray();
    ~Bpixelarray();
    void Clear(unsigned int color);
    bool Init(unsigned int width,
	      unsigned int height);
    bool Init(std::string file);
    //unsigned int &GetSetPixel(unsigned int pos);
    //unsigned int &GetSetPixel(unsigned int x,
    //			      unsigned int y);
    void placePixel(Pos &pos,
		    unsigned int colo);
    void Blit(Bpixelarray &other,
	      AcuPos const &start,
	      AcuPos const &size,
	      float const &rotate);
    void Blit(Bpixelarray &other,
	      AcuPos const &start,
	      AcuPos const &size);
    void Blit(Bpixelarray &other,
	      Pos const &start,
	      AcuPos const &size,
	      int alegence);
    t_bunny_clipable *GetClip()const;
    Pos GetSize();
    void rectangle(AcuPos &start,
		   AcuPos &size,
		   unsigned int background,
		   unsigned int outline);
    void setLine(AcuPos &start,
		 AcuPos &end,
		 unsigned int color);
    void drawText(std::shared_ptr<Bpixelarray> &font,
		  std::string str,
		  AcuPos &pos);

    VertexArray<5000> recVec;
    VertexArray<1000> textVec;
    VertexArray<5000000> lineVec;
    VertexArray<20000> pixVec;

  private:
    void print_char(std::shared_ptr<Bpixelarray> &font,
		    char c,
		    AcuPos &pos);

    //t_bunny_pixelarray *px;
    t_bunny_picture *px; // for GPU compute
    std::unique_ptr<unsigned int[]> pixels;
  };
};

#endif//__BPIXELARRAY_HH__
