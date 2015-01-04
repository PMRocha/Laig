#include "SceneAmbient.h"

SceneAmbient::SceneAmbient():sphere(12,30,30)
{
}

void SceneAmbient::draw(){
	glFrontFace(GL_CW);
	sphere.draw("sky.jpg");
	glFrontFace(GL_CCW);
}