#include "SceneAmbient.h"

SceneAmbient::SceneAmbient():sphere(20,30,30)
{
}

void SceneAmbient::draw(){
	glFrontFace​(GL_CW);
	sphere.draw();
	glFrontFace(GL_CCW);
}