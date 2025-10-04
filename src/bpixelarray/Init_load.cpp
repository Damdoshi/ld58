#include "Bpixelarray.hh"

bool ef::Bpixelarray::Init(std::string file)
{
    if(px != NULL)
    {
        pixels.release();
        //bunny_delete_clipable(&px->clipable);
	bunny_delete_clipable(px);
    }
    if((px = bunny_load_picture(&file[0])) == NULL)
      if((px = bunny_load_picture("res/sprite/FUCK.png")) == NULL)
	 return true;
    //std::unique_ptr<unsigned int[]> tmp ((unsigned int *)px->pixels);

    //pixels = std::move(tmp);
    recVec.length = 0;
    lineVec.length = 0;
    pixVec.length = 0;
    return false;
}
