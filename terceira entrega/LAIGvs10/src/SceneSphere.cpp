#include "SceneSphere.h"

#define PI acos(-1.0)

SceneSphere::SceneSphere(float radius,int slices, int stacks)
{

	this->radius=radius;
	this->stacks=stacks;
	this->slices=slices;
}


void SceneSphere::draw(void)
{
	GLUquadric *quad= gluNewQuadric();
	gluQuadricTexture(quad,GL_TRUE);
	gluQuadricOrientation(quad,GLU_OUTSIDE);
	gluSphere(quad,radius,slices,stacks);
}

void SceneSphere::draw(string tex)
{
	CGFtexture texture = CGFtexture("sky.jpg");
	texture.apply();
	GLUquadric *quad= gluNewQuadric();
	gluQuadricTexture(quad,GL_TRUE);
	gluQuadricOrientation(quad,GLU_OUTSIDE);
	gluSphere(quad,radius,slices,stacks);
}



SceneSphere::~SceneSphere(void)
{
}
