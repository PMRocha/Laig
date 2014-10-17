#include "Texture.h"


Texture::Texture(string id,string file, float sWrap, float tWrap): CGFtexture(file)
{
	this->id=id;
}


Texture::~Texture(void)
{
}

float Texture::getTWrap()
{
	return tWrap;
}
	
float Texture::getSWrap()
{
	return sWrap;
}