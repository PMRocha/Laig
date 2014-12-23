#include "ScenePiece.h"

#define PI acos(-1.0)

ScenePiece::ScenePiece(double x, double y, double z):piece(1,1,0.5,20,20)
{

	coords.x=x;
	coords.y=y;
	coords.z=z;
}


void ScenePiece::draw(void)
{
	glPushMatrix();
	glScalef(0.5,1,0.5);
	glRotatef(-90,1,0,0);
	glTranslatef(coords.x,coords.y, coords.z);
	piece.draw();
	glPopMatrix();
}



ScenePiece::~ScenePiece(void)
{
}

void ScenePiece::move(float deltaTime) {
	coords.x += 1 * deltaTime;
	std::cout << deltaTime << std::endl;
}