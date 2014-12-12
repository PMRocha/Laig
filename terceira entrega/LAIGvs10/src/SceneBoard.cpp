#include "SceneBoard.h"

#define PI acos(-1.0)

SceneBoard::SceneBoard():block()
{

}


void SceneBoard::draw(void)
{
	glPushMatrix();
	for(unsigned int i = 0; i < 5; i++) {
		block.draw();
		glTranslatef(2.0f, 0.0f, 0.0f);
	}
	glPopMatrix();
}



SceneBoard::~SceneBoard(void)
{
}
