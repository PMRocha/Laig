#ifndef _SCENEOBJECT_H_
#define _SCENEOBJECT_H_
#include "CGFobject.h"

class SceneObject:public CGFobject
{
protected:
		float textS,textT;
public:
	virtual void setTextS(float s);
	virtual void setTextT(float t);
	float getTextS();
	float getTextT();
	SceneObject(void);
	~SceneObject(void);

};

#endif
