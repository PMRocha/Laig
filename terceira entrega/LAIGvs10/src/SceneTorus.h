#ifndef _SCENETORUS_H_
#define _SCENETORUS_H_
#include "SceneObject.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Point.h" 
using namespace std;

class SceneTorus:public SceneObject
{
private:
	float inner;
	float outer;
	int slices;
	int loop;
	int row;
	int column;
	float ringRadius;
	vector <vector<Point>> points;
	vector <vector<Point>> normals;
	vector <vector<Point>> texts;

public:
	SceneTorus(float inner,float outer,int slices,int loop);
	~SceneTorus(void);
	void normalsCalc();
	Point normalCalc(int i, int j);
	void textsCalc();
	Point textCalc(int i, int j,float angle);
	void draw();
	void move(int row, int column);
};

#endif