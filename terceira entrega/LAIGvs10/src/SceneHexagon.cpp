#include "SceneHexagon.h"

#define PI acos(-1.0)

SceneHexagon::SceneHexagon()
{
}


void SceneHexagon::draw(void)
{
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	for(int i = 0; i < 6; ++i) {
		glVertex3d(sin(i/6.0*2*PI),cos(i/6.0*2*PI),0);
	}
	glEnd();
}



SceneHexagon::~SceneHexagon(void)
{
}
