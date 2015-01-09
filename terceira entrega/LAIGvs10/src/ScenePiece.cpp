#include "ScenePiece.h"

#define PI acos(-1.0)

ScenePiece::ScenePiece(double x, double y, double z):piece(1,1,0.5,20,20)
{

	coords.x=x;
	coords.y=y;
	coords.z=z;
	row =0;
	column=0;
}


void ScenePiece::draw(void)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D); 

	texture->apply();

	glPushName(-1);	
	glLoadName(row);
	glPushName(column);
	glTranslatef(coords.x,coords.y, coords.z);
	//slide along table's y axis
	glTranslatef(0.0f, 0.0f, (1.5*row));
	for(int i=0;i<row;i++){
		glTranslatef(-sin(PI/3.0), 0.0f,0.0f);
	}
	//slide along table's x axis
	for(int i=0;i<column;i++){
		glTranslatef(2*sin(PI/3.0), 0.0f,0.0f);
	}
	
	glScalef(0.5,1,0.5);
	glRotatef(-90,1,0,0);

	piece.draw();
	glPopName();
	glPopName();
	glPopMatrix();
}

ScenePiece::~ScenePiece(void)
{
}

void ScenePiece::move(float deltaTime) {
	//coords.x += 10 * deltaTime;
	//std::cout << deltaTime << std::endl;
}

void ScenePiece::setColor(char type, CGFtexture * scene){
	color=type;
	if(type = 'b')
		texture = scene;
	else
		texture = scene;
}

void ScenePiece::setName(int row, int column){
	this->row = row;
	this->column = column;
}

bool ScenePiece::checkName(int row, int column) {
	return (this->row == row && this->column == column);
}