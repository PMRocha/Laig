#ifndef SCENEPLANE_H
#define SCENEPLANE_H

#include <string>
#include "CGFtexture.h"
#include "SceneObject.h"
#include <iomanip>
#include <iostream>

using namespace std;

class ScenePlane : public SceneObject
{
	CGFtexture *PlaneTex;
	int parts, dimensions;
	GLfloat **controlPoints, **normalPoints, **texturePoints;
	void calcTexPoints();
	void calcNormalPoints();
	void calcControlPoints();
public:
	ScenePlane(int parts);
	~ScenePlane();
	void draw();
};
#endif