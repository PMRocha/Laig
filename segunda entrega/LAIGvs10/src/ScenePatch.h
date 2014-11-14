#ifndef _SCENEPATCH_H_
#define _SCENEPATCH_H_


#include "SceneObject.h"
#include <iostream>
#include <vector>

using namespace std;

class ScenePatch:public SceneObject
{
private:
	int drawmode,index,order,partsU,partsV;
	float** controlPoints,normalPoints,texturePoints;
	string compute;

	//order 1
	float controlPoints1 [4][3];
	float texturePoints1[4][2];

	//order 2
	float controlPoints2 [9][3];
	float texturePoints2[9][2];

	//order 3
	float controlPoints3 [16][3];
	float texturePoints3[16][2];

public:
	ScenePatch(int order,int partsU, int partsV,string compute);
	void addCntrPoint(float x,float y, float z);
	~ScenePatch(void);
	void draw();
};

#endif