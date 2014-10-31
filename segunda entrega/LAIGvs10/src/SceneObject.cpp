#include "SceneObject.h"


SceneObject::SceneObject(void)
{
	textS=1;
	textT=1;
}


SceneObject::~SceneObject(void)
{
}

void SceneObject::setTextS(float s)
{
	textS=s;
}
	
void SceneObject::setTextT(float t)
{
	textT=t;
}

float SceneObject::getTextS()
{
	return textS;
}


float SceneObject::getTextT()
{
	return textT;
}