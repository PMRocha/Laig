#include "SceneFlag.h"

SceneFlag::SceneFlag() :
	plane(100)
{

}

SceneFlag::SceneFlag(std::string texture) :
	plane(100)
{
	/*apply texture? idk... */
}

void SceneFlag::draw() {
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, 2.0f);
	glScalef(10.0f, 1.0f, 10.0f);
	plane.draw();
	glPopMatrix();
}