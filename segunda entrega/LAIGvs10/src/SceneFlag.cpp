#include "SceneFlag.h"

SceneFlag::SceneFlag() {

}

SceneFlag::SceneFlag(std::string texture) {
	/*apply texture? idk... */
}

void SceneFlag::draw() {
	glBegin(GL_POLYGON);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 3.0f);
		glVertex3f(3.0f, 0.0f, 3.0f);
		glVertex3f(3.0f, 0.0f, 0.0f);
	glEnd();
}