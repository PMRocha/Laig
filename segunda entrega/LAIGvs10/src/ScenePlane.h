#ifndef _SCENEPLANE_H_
#define _SCENEPLANE_H_

#include "glui.h"
#include "glut.h"
#include "SceneObject.h"
#include "CGFtexture.h"

class ScenePlane:public SceneObject
{
private:
	int part;
	float controlPoints[4][3];
	float texturePoints[4][2];
	float normalPoints[4][3];

public:
	ScenePlane(int part);
	~ScenePlane(void);
	void draw();
};

#endif
