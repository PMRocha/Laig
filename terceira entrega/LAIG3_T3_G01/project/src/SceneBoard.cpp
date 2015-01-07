#include "SceneBoard.h"

#define PI acos(-1.0)

SceneBoard::SceneBoard():block()
{

}


void SceneBoard::draw(void)
{
	glPushMatrix();

	glPushMatrix();
	for(unsigned int i = 0; i < 5; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();
	
	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);
	glPushMatrix();
	for(unsigned int i = 0; i < 6; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();
		
	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 7; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 8; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 9; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 8; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 7; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 6; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 5; i++) {
		block.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glPopMatrix();
	//drawPieces();
}



SceneBoard::~SceneBoard(void)
{
}

void SceneBoard::drawPieces(void)
{
	glPushMatrix();

	glPushMatrix();
	for(unsigned int i = 0; i < 5; i++) {
		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);

	}
	glPopMatrix();
	
	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);
	glPushMatrix();
	for(unsigned int i = 0; i < 6; i++) {

		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();
		
	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 7; i++) {

		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 8; i++) {

		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(-sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 9; i++) {

		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 8; i++) {
		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 7; i++) {
		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 6; i++) {
		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glTranslatef(sin(PI/3.0), 0.0f, 1.5f);

	glPushMatrix();
	for(unsigned int i = 0; i < 5; i++) {
		ScenePiece p = ScenePiece(2.0*sin(PI/3.0), 0.0f, 0.0f);
		p.draw();
		glTranslatef(2.0*sin(PI/3.0), 0.0f, 0.0f);
	}
	glPopMatrix();

	glPopMatrix();
}
