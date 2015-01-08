#include "SceneAmbient.h"

SceneAmbient::SceneAmbient():sphere(20,30,30)
{
}

void SceneAmbient::draw(Appearance * tex){
	glFrontFace(GL_CW);
	
	tex->apply();
	sphere.draw();
	glFrontFace(GL_CCW);
}