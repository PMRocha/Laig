#ifndef APPEARANCE_H
#define APPEARANCE_H
#include "CGFAppearance.h"
class Appearance :
	public CGFappearance
{
	string textureId;
	float sWrap,tWrap;
public:
	Appearance(float ambient[],float diffuse[],float specular[],float emissive[],float shininess,float sWrap,float tWrap,string textureId);
	Appearance(void);
	~Appearance(void);
	string getTextureId();
	float getTWrap();
	float getSWrap();
	
};

#endif