#include "SceneFlag.h"

SceneFlag::SceneFlag() :
	plane(100)
{

}

SceneFlag::SceneFlag(std::string texture) :
	plane(100),
	shader("flag.vert", "flag.frag", texture)
{
	
}

void SceneFlag::draw() {
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, 2.0f);
	glScalef(10.0f, 1.0f, 10.0f);

	shader.bind();

	plane.draw();

	shader.unbind();

	glPopMatrix();
}