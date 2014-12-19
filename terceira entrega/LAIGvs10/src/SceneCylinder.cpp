#include "SceneCylinder.h"
#define PI acos(-1.0)

SceneCylinder::SceneCylinder(float base,float top,float height,int slices,int stacks)
{

	CGFobject();

	this->top=top;
	this->base=base;
	this->height=height;
	this->slices=slices;
	this->stacks=stacks;

	deltaRadius=(top-base)/(float)stacks;
	float radius=base;
	float deltaH=height/stacks;
	float deltaAngle=(2*PI)/(float)slices;

	vector <Point> help;
	Point point;


	for (float i=0;i<=height;i+=deltaH)
	{
		for (float j=0;j<=2*PI+deltaAngle;j+=deltaAngle)
		{
			point.x=radius*cos(j);
			point.y=radius*sin(j);
			point.z=i;

			help.push_back(point);
		}
		points.push_back(help);
		help.clear();
		radius+=deltaRadius;
	}

	normalsCalc();
	textsCalc();

}


SceneCylinder::~SceneCylinder(void)
{
}

void SceneCylinder::draw(void)
{
	int nextP,nextC;
	float angle=(2*PI)/(float)slices;
	//draw base
	glBegin(GL_POLYGON);
	for (int i =  points[0].size()-1; i >=0 ;i--)
	{
	
		glTexCoord2f(0.5 + cos(i*angle)/2.0,0.5 + sin(i*angle)/2.0);
		glNormal3f( 0,0,1);
		glVertex3f( points[0][i].x,points[0][i].y,points[0][i].z);
	
	}  
	glEnd();


	//draw top
	glBegin(GL_POLYGON);
	for (unsigned int i =  0; i <points[points.size()-1].size();i++)
	{
		glTexCoord2f(0.5 + cos(i*angle)/2.0,0.5 + sin(i*angle)/2.0);
		glNormal3f( 0,0,-1);
		glVertex3f( points[points.size()-1][i].x,points[points.size()-1][i].y,points[points.size()-1][i].z);
	} 
	glEnd();


	//draw sides
	//I->HORIZONTAL row
	for (unsigned int i = 0; i < points.size()-1;i++)
	{
		//J->VERTICAL column
		glBegin(GL_QUADS);
		for (unsigned int j = 0; j < points[i].size()-1;j++)
		{
			
			nextP=j+1;

			nextC=i+1;

			glTexCoord2f(texts[i][j].x,texts[i][j].y);
			glNormal3f(normals[i][j].x,normals[i][j].y,normals[i][j].z);
			glVertex3f( points[i][j].x,points[i][j].y,points[i][j].z);

			glTexCoord2f(texts[i][nextP].x,texts[i][nextP].y);
			glNormal3f(normals[i][nextP].x,normals[i][nextP].y,normals[i][nextP].z);
			glVertex3f( points[i][nextP].x,points[i][nextP].y,points[i][nextP].z);  

			glTexCoord2f(texts[nextC][nextP].x,texts[nextC][nextP].y);
			glNormal3f(normals[nextC][nextP].x,normals[nextC][nextP].y,normals[nextC][nextP].z);
			glVertex3f( points[nextC][nextP].x,points[nextC][nextP].y,points[nextC][nextP].z);

			glTexCoord2f(texts[nextC][j].x,texts[nextC][j].y);
			glNormal3f(normals[nextC][j].x,normals[nextC][j].y,normals[nextC][j].z);
			glVertex3f( points[nextC][j].x,points[nextC][j].y,points[nextC][j].z);

		}  
		glEnd();
	}
}

void SceneCylinder::normalsCalc()
{
	vector<Point> lineNormal;
	Point help;

	for (unsigned int i = 0; i < points.size();i++)
	{
		for (unsigned int j = 0; j < points[i].size();j++)
		{
			help=normalCalc(i,j);
			lineNormal.push_back(help);
		}
		normals.push_back(lineNormal);
		lineNormal.clear();
	}
}

Point SceneCylinder::normalCalc(int i,int j)
{

	int nextP=0,nextC=0;

	if(j==points[i].size()-1)
		nextP=j;
	else
		nextP=j+1;

	if(i==points.size()-1)
		nextC=0;
	else
		nextC=i+1;

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

	e1.x = points[i][nextP].x - points[i][j].x;
	e1.y = points[i][nextP].y - points[i][j].y;
	e1.z = points[i][nextP].z - points[i][j].z;
	e2.x = points[nextC][j].x - points[i][j].x;
	e2.y = points[nextC][j].y - points[i][j].y;
	e2.z = points[nextC][j].z - points[i][j].z;
	n.x = (e1.y * e2.z) - (e1.z * e2.y);
	n.y = (e1.z * e2.x) - (e1.x * e2.z);
	n.z = (e1.x * e2.y) - (e1.y * e2.x);
	// Normalize (divide by root of dot product)
	l = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	n.x /= l;
	n.y /= l;
	n.z /= l;

	return n;
}


void SceneCylinder::textsCalc()
{
	float angle=0;
	vector<Point> lineText;
	Point help;

	for (unsigned int i = 0; i < points.size();i++)
	{
		for (unsigned int j = 0; j < points[i].size();j++)
		{

			help=textCalc(i,j,angle);
			lineText.push_back(help);
			angle+=(2*PI)/(float)slices;
		}
		texts.push_back(lineText);
		lineText.clear();
		angle=0;
	}
}

Point SceneCylinder::textCalc(int i,int j,float angle)
{
	Point t;
	t.x=0;
	t.y=0;
	t.z=0;


		t.x = angle / (float)(2*PI);
		t.y =  points[i][j].z / (height+top/2.0+base/2.0);

	return t;
}
