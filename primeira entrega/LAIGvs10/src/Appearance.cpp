#include "Appearance.h"


Appearance::Appearance(void)
{
}


Appearance::~Appearance(void)
{
}

Appearance::Appearance(float ambient[],float diffuse[],float specular[],float emissive[],float shininess,float sWrap,float tWrap,string textureId): CGFappearance(ambient,diffuse,specular,shininess)
{
		this->sWrap=sWrap;
		this->tWrap=tWrap;
		this->setTextureWrap(sWrap,tWrap);
		this->textureId=textureId;
}

string Appearance::getTextureId()
{
	return textureId;
}


float Appearance::getTWrap()
{
	return tWrap;
}
	
float Appearance::getSWrap()
{
	return sWrap;
}
