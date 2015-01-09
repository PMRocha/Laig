#include "SceneTorus.h"

#define PI acos(-1.0)

SceneTorus::SceneTorus(float inner,float outer,int slices,int loop)
{
	this->inner=inner;
	this->outer=outer;
	this->slices=slices;
	this->loop=loop;
	float alphaJump=(2*PI)/(float)slices;
	float phiJump=(PI)/(float)loop;
	Point point;
	ringRadius = (outer-inner)/2.0;
	float mediumRadius=ringRadius+inner;
	vector<Point> help;

	row =0; column =0; 

	for (double phi = 0; phi < 2*PI+phiJump;phi+=phiJump) // Elevation [0, PI]
	{
		for (double alpha = 0; alpha < 2*PI+alphaJump; alpha += alphaJump) // Azimuth [0, 2PI]
		{
			point.x= (outer+inner*cos(phi))*cos(alpha);
			point.y= (outer+inner*cos(phi))*sin(alpha);
			point.z= inner*sin(phi);
			help.push_back(point);

		}
		points.push_back(help);
		help.clear();
	}


	normalsCalc();
	textsCalc();
}

void SceneTorus::draw()
{

	int nextP,nextC;
	float auxTextX=0,auxTextY=0;

	glTranslatef(0.0f, 0.0f, (1.5*row));
	for(int i=0;i<row;i++){
		glTranslatef(-sin(PI/3.0), 0.0f,0.0f);
	}
	//slide along table's x axis
	for(int i=0;i<column;i++){
		glTranslatef(2*sin(PI/3.0), 0.0f,0.0f);
	}
	glRotatef(-90,1,0,0);

	glScalef(0.5,0.5,0.5);

	for (unsigned int i = 0; i < points.size()-1;i++)
	{

		glBegin(GL_TRIANGLE_STRIP);
		for (unsigned int j = 0; j < points[i].size()-1;j++)
		{
		
				nextP=j+1;
                nextC=i+1;


			glTexCoord2f( texts[i][j].x,texts[i][j].y);
			glNormal3f( normals[i][j].x,normals[i][j].y,normals[i][j].z);
			glVertex3f( points[i][j].x,points[i][j].y,points[i][j].z);

			glTexCoord2f( texts[i][nextP].x,texts[i][nextP].y);
			glNormal3f( normals[i][nextP].x,normals[i][nextP].y,normals[i][nextP].z);  
			glVertex3f( points[i][nextP].x,points[i][nextP].y,points[i][nextP].z);  

			glTexCoord2f( texts[nextC][j].x,texts[nextC][j].y);
			glNormal3f(normals[nextC][j].x,normals[nextC][j].y,normals[nextC][j].z);
			glVertex3f( points[nextC][j].x,points[nextC][j].y,points[nextC][j].z);

			glTexCoord2f( texts[nextC][nextP].x,texts[nextC][nextP].y);
			glNormal3f( normals[nextC][nextP].x,normals[nextC][nextP].y,normals[nextC][nextP].z); 
			glVertex3f( points[nextC][nextP].x,points[nextC][nextP].y,points[nextC][nextP].z);



		}  
		glEnd();

	}
	
}

void SceneTorus::normalsCalc()
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

Point SceneTorus::normalCalc(int i,int j)
{

	int nextP=0,nextC=0;

	if(j==points[i].size()-1)
		nextP=0;
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


void SceneTorus::textsCalc()
{
	vector<Point> lineText;
	Point help;
	float angle=0;

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

Point SceneTorus::textCalc(int i,int j,float angle)
{
	Point t;
	t.x=0;
	t.y=0;
	t.z=0;




	t.x = j/(float)loop;
	t.y = i/(float)slices;
	
	return t;
}


SceneTorus::~SceneTorus(void)
{

}

void SceneTorus::move(int row, int column)
{
	this->row = row;
	this->column = column;
}
