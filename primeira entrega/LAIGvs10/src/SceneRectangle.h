#ifndef _SCENERECTANGLE_H_
#define _SCENERECTANGLE_H_


#include "SceneObject.h"
#include <iostream>

class SceneRectangle:public SceneObject
{
private:
	float xi,xf,yi,yf;
	float comp,larg;
public:
	SceneRectangle(void);
	SceneRectangle(float xi,float yi, float xf, float yf);
	~SceneRectangle(void);
	void draw();
	void setTextS(float s);
	void setTextT(float t);
};
#endif
