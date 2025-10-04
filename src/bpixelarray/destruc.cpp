#include"Bpixelarray.hh"

ef::Bpixelarray::~Bpixelarray()
{
    pixels.release();
    //bunny_delete_clipable(&px->clipable);
    bunny_delete_clipable(px);
    //free(recVec.vertex);
    //free(lineVec.vertex);
    //free(pixVec.vertex);
}
