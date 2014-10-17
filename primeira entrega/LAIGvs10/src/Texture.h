#ifndef TEXTURE_H
#define TEXTURE_H
#include "CGFtexture.h"
class Texture :
	public CGFtexture
{
	string id;
	float sWrap,tWrap;
public:
	Texture(string id,string file, float sWrap, float tWrap);
	~Texture(void);
	float getTWrap();
	float getSWrap();
};

#endif