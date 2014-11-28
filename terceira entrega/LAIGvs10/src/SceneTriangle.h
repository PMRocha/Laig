#ifndef _SCENETRIANGLE_H_
#define _SCENETRIANGLE_H_

#include "SceneObject.h"
#include <iostream>
#include <vector>
#include <math.h> 
#include "Point.h"

class SceneTriangle:public SceneObject
{
private:
	Point point1;
	Point point2;
	Point point3;
	vector<Point> normals;
	float textS,textT;
	float a1,b1,c1,beta;
public:
	SceneTriangle(void);
	SceneTriangle(float a[3],float b[3],float c[3]);
	void normalCalc();
	~SceneTriangle(void);
	void draw();
	void setTextS(float s);
	void setTextT(float t);
};

#endif