#ifndef _SCENESPHERE_H_
#define _SCENESPHERE_H_
#include "SceneObject.h"
#include <vector>
#include <iostream>
#include "Texture.h"
#include <math.h>
using namespace std;

class SceneSphere:public SceneObject
{
private:
	float radius;
	int stacks;
	int slices;
public:
	SceneSphere();
	SceneSphere(float radius,int slices, int stacks);
	~SceneSphere(void);
	void draw(void);
	void draw(string tex);
};

#endif