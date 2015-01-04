#ifndef _SCENEAMBIENT_H_
#define _SCENEAMBIENT_H_
#include "SceneSphere.h"
#include <GL/GL.h>

using namespace std;

class SceneAmbient
{
private:
	SceneSphere sphere;
public:
	SceneAmbient();
	void draw();
};

#endif