#include"Bpixelarray.hh"

ef::Bpixelarray::~Bpixelarray()
{
    pixels.release();
    //bunny_delete_clipable(&px->clipable);
    if (!isOutside)
      bunny_delete_clipable(px);
    //free(recVec.vertex);
    //free(lineVec.vertex);
    //free(pixVec.vertex);
}
