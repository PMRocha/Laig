#ifndef _SCENECYLINDER_H_
#define _SCENECYLINDER_H_
#include "SceneObject.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

class SceneCylinder:public SceneObject
{
private:
	float top;
    float base;
	float height;
	int slices;
	int stacks;
	float deltaRadius;
	vector <vector<Point>> points;
	vector <vector<Point>> normals;
	vector <vector<Point>> texts;

public:
	SceneCylinder(float base,float top,float height,int slices,int stacks);
	~SceneCylinder(void);
	void normalsCalc();
	Point normalCalc(int i,int j);
	void textsCalc();
	Point textCalc(int i, int j,float angle);
	void draw(void);
};

#endif