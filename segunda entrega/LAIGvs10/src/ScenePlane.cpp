#include "ScenePlane.h"


ScenePlane::ScenePlane(int part)
{
	this->part=part;

	controlPoints[0][0]=1.0;
	controlPoints[0][1]=0;
	controlPoints[0][2]=0.0;

	controlPoints[1][0]=1.0;
	controlPoints[1][1]=0;
	controlPoints[1][2]=1.0;

	controlPoints[2][0]=0.0;
	controlPoints[2][1]=0;
	controlPoints[2][2]=0.0;

	
	controlPoints[3][0]=0.0;
	controlPoints[3][1]=0;
	controlPoints[3][2]=1.0;

	texturePoints[0][0]=1;
	texturePoints[0][1]=1;

	texturePoints[1][0]=0;
	texturePoints[1][1]=1;

	texturePoints[2][0]=1;
	texturePoints[2][1]=0;

	texturePoints[3][0]=0;
	texturePoints[3][1]=0;
	

	normalPoints[0][0]=0;
	normalPoints[0][1]=1.0;
	normalPoints[0][2]=0.0;

	normalPoints[1][0]=0;
	normalPoints[1][1]=1.0;
	normalPoints[1][2]=0;

	normalPoints[2][0]=0.0;
	normalPoints[2][1]=1.0;
	normalPoints[2][2]=0.0;

	
	normalPoints[3][0]=0.0;
	normalPoints[3][1]=1.0;
	normalPoints[3][2]=0;
}


ScenePlane::~ScenePlane(void)
{

}

void ScenePlane::draw()
{
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &controlPoints[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &texturePoints[0][0]);
	glMap2f(GL_MAP2_NORMAL, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &normalPoints[0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glMapGrid2f(part, 0.0,1.0, part, 0.0,1.0); 
	glEvalMesh2(GL_FILL, 0,part, 0,part);

	glColor3f(1.0, 1.0, 0.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
}