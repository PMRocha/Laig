#include "ScenePlane.h"

ScenePlane::ScenePlane(int parts){
	this->parts=parts;
	PlaneTex = new CGFtexture("tire.png");
	dimensions = parts+1;

	texturePoints = new GLfloat*[dimensions];
	for (int i = 0; i < dimensions; ++i)
		texturePoints[i] = new GLfloat[3];

	controlPoints = new GLfloat*[dimensions];
	for (int i = 0; i < dimensions; ++i)
		controlPoints[i] = new GLfloat[3];


	normalPoints = new GLfloat*[dimensions];
	for (int i = 0; i < dimensions; ++i)
		normalPoints[i] = new GLfloat[3];

	calcControlPoints();
	calcNormalPoints();
	calcTexPoints();
}

ScenePlane::~ScenePlane(){
	delete(PlaneTex);

	for (int i = 0; i < 3; ++i)
		delete [] texturePoints[i];
	delete [] texturePoints;

	for (int i = 0; i < 3; ++i)
		delete [] controlPoints[i];
	delete [] controlPoints;

	for (int i = 0; i < 3; ++i)
		delete [] normalPoints[i];
	delete [] normalPoints;
}

void ScenePlane::calcControlPoints(){
	int index=0;
	for(float i=0; i<=1;i+(1/parts)){
		for(float j=0;j<=1;(1/parts)){
		controlPoints[index][0] = j;
		controlPoints[index][1] = 0.0;
		controlPoints[index][2] = i;
		index+=3;
		}
	}
}

void ScenePlane::calcNormalPoints(){
	for(int i=0; i<dimensions;i+3){
		normalPoints[i][0]  = 0.0;
		normalPoints[i+1][1] = 1.0;
		normalPoints[i+2][2] = 0.0;
	}
}

void ScenePlane::calcTexPoints(){
	int index=0;
	for(GLfloat i=0; i<=1;i+(1/parts)){
		for(GLfloat j=0;j<=1;(1/parts)){
		controlPoints[index][0] = j;
		controlPoints[index+1][1] = 0.0;
		controlPoints[index+2][2] = i;
		index+=3;
		}
	}
}

void ScenePlane::draw(){


	glColor3f(1.0,1.0,1.0);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, parts,  0.0, 1.0, 3*parts, parts,  &controlPoints[0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, parts,  0.0, 1.0, 3*parts, parts,  &normalPoints[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, parts,  0.0, 1.0, 3*parts, parts,  &texturePoints[0][0]);

	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	glMapGrid2f(10, 0.0,1.0, 15, 0.0,1.0); 

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	PlaneTex->apply();


	glEvalMesh2(GL_FILL, 0,dimensions, 0,dimensions);		// GL_POINT, GL_LINE, GL_FILL
	glColor3f(1.0, 1.0, 0.0);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
}