#include"Bpixelarray.hh"

ef::Bpixelarray::Bpixelarray()
  :
  isOutside(false);
{
    px = NULL;
    recVec.length = 0;
    //recVec.vertex = new Vertex[100000]();
    lineVec.length = 0;
    //lineVec.vertex = new Vertex[100000]();
    pixVec.length = 0;
    //pixVec.vertex = new Vertex[100000]();
    pixVec.length = 0;
    textVec.length = 0;
}
ef::Bpixelarray::Bpixelarray(t_bunny_picture &pic)
  : px(&pic), isOutside(false)
{
  recVec.length = 0;
  lineVec.length = 0;
  pixVec.length = 0;
  textVec.length = 0;
}

