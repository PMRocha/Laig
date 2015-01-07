#include "SceneTriangle.h"


SceneTriangle::SceneTriangle(void)
{
}

SceneTriangle::SceneTriangle(float a[3],float b[3],float c[3])
{

	point1.x=a[0];
	point1.y=a[1];
	point1.z=a[2];
	point2.x=b[0];
	point2.y=b[1];
	point2.z=b[2];
	point3.x=c[0];
	point3.y=c[1];
	point3.z=c[2];

	normalCalc();

	textS=1;
	textT=1;

	c1=sqrt(powf((point3.x-point2.x),2.0)+powf((point3.y-point2.y),2.0)+powf((point3.z-point2.z),2.0));
	b1=sqrt(powf((point1.x-point2.x),2.0)+powf((point1.y-point2.y),2.0)+powf((point1.z-point2.z),2.0));
	a1=sqrt(powf((point3.x-point1.x),2.0)+powf((point3.y-point1.y),2.0)+powf((point3.z-point1.z),2.0));
	beta=acos((powf(a1,2)-powf(b1,2)+powf(c1,2))/(2*a1*c1));
}



SceneTriangle::~SceneTriangle(void)
{
}

void SceneTriangle::draw()
{

	glBegin(GL_TRIANGLES);
	glTexCoord2f(1/(float)textS*(c1-a1*cos(beta)),(1/(float)textS*(a1*cos(beta))));
	glNormal3f(normals[0].x,normals[0].y,normals[0].z);
	glVertex3f( point1.x, point1.y,point1.z);

	glTexCoord2f(0,0);
	glNormal3f(normals[1].x,normals[1].y,normals[1].z);
	glVertex3f( point2.x, point2.y,point2.z);

	glTexCoord2f(c1/(float)textS,0);
	glNormal3f(normals[2].x,normals[2].y,normals[2].z);
	glVertex3f( point3.x, point3.y,point3.z);		
	glEnd();

}

void SceneTriangle::normalCalc()
{

	Point e1,e2,n;

	e1.x=0;
	e1.y=0;
	e1.z=0;
	e2.x=0;
	e2.y=0;
	e2.z=0;
	n.x=0;
	n.y=0;
	n.z=0;

	float l;

	e1.x = point2.x - point1.x;
	e1.y = point2.y - point1.y;
	e1.z = point2.z - point1.z;
	e2.x = point3.x - point1.x;
	e2.y = point3.y - point1.y;
	e2.z = point3.z - point1.z;
	n.x = (e1.y * e2.z) - (e1.z * e2.y);
	n.y = (e1.z * e2.x) - (e1.x * e2.z);
	n.z = (e1.x * e2.y) - (e1.y * e2.x);
	// Normalize (divide by root of dot product)
	l = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	n.x /= l;
	n.y /= l;
	n.z /= l;

	normals.push_back(n);


	e1.x = point1.x - point2.x;
	e1.y = point1.y - point2.y;
	e1.z = point1.z - point2.z;
	e2.x = point3.x - point2.x;
	e2.y = point3.y - point2.y;
	e2.z = point3.z - point2.z;
	n.x = (e1.y * e2.z) - (e1.z * e2.y);
	n.y = (e1.z * e2.x) - (e1.x * e2.z);
	n.z = (e1.x * e2.y) - (e1.y * e2.x);
	// Normalize (divide by root of dot product)
	l = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	n.x /= l;
	n.y /= l;
	n.z /= l;

	normals.push_back(n);

	e1.x = point1.x - point3.x;
	e1.y = point1.y - point3.y;
	e1.z = point1.z - point3.z;
	e2.x = point2.x - point3.x;
	e2.y = point2.y - point3.y;
	e2.z = point2.z - point3.z;
	n.x = (e1.y * e2.z) - (e1.z * e2.y);
	n.y = (e1.z * e2.x) - (e1.x * e2.z);
	n.z = (e1.x * e2.y) - (e1.y * e2.x);
	// Normalize (divide by root of dot product)
	l = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	n.x /= l;
	n.y /= l;
	n.z /= l;

	normals.push_back(n);
}

void SceneTriangle::setTextS(float s)
{
	textS=s;
}
	
void SceneTriangle::setTextT(float t)
{
	textT=t;
}