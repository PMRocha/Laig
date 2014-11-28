#ifndef _SCENEHEXAGON_H_
#define _SCENEHEXAGON_H_
#include "SceneObject.h"
#include "glui.h"
#include "glut.h"
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class SceneHexagon:public SceneObject
{
private:

public:
	SceneHexagon();
	~SceneHexagon(void);
	void draw(void);
};

#endif