#include "SceneAmbient.h"

SceneAmbient::SceneAmbient():sphere(12,30,30)
{
}

void SceneAmbient::draw(){
	glFrontFace(GL_CW);
	CGFtexture("sky.jpg").apply();
	sphere.draw();
	glFrontFace(GL_CCW);
}