#include "SceneBlock.h"

#define PI acos(-1.0)

SceneBlock::SceneBlock():rec1(3)
{

}


void SceneBlock::draw(void)
{

	glRotatef(30.0f,0.0f,1.0f,0.0f);

	double texx[6] = {1,0.75,0.25,0,0.25,0.75};

	double texy[6] = {0.5,1,1,0.5,0,0};

	//bases
	glPushMatrix();
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	for(int i = 0; i < 6; ++i) {
		glTexCoord2f(texx[i],texy[i]);
		glVertex3d(sin(i/6.0*2*PI),cos(i/6.0*2*PI),0);
		
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i = 6; i > 0; --i) {
		glTexCoord2f(texx[i-1],texy[i-1]);
		glVertex3d(sin(i/6.0*2*PI),cos(i/6.0*2*PI),0.5);
		
	}
	glEnd();
	glPopMatrix();
	
	//sides
	glPushMatrix();
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	rec1.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(60.0, 0.0, 1.0, 0.0);
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	
	rec1.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(120.0, 0.0, 1.0, 0.0);
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	
	rec1.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	
	rec1.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(240.0, 0.0, 1.0, 0.0);
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	
	rec1.draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(300.0, 0.0, 1.0, 0.0);
	glTranslatef(sin(1/6.0*2*PI), 0.0, -0.5);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(0.5, 1.0, 1.0);
	
	rec1.draw();
	glPopMatrix();
}



SceneBlock::~SceneBlock(void)
{
}
