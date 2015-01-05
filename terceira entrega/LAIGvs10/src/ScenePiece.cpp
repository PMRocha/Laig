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
	texture.apply();
	glPushName(-1);	
	glLoadName(row);
	glPushName(column);
	glTranslatef(coords.x,coords.y, coords.z);
	glTranslatef(0.0f, 0.0f, (1.5*row));
	if(column <= 4)
	{
		for(int i=0;i<column;i++){
			glTranslatef(2*sin(PI/3.0), 0.0f,0.0f);
		}
		
	}
	else
	{
		for(int i=0;i<(8-column);i++){
			glTranslatef(2*sin(PI/3.0), 0.0f,0.0f);
		}
	}
	glScalef(0.5,1,0.5);
	glRotatef(-90,1,0,0);

	piece.draw();
	glPopMatrix();
}

ScenePiece::~ScenePiece(void)
{
}

void ScenePiece::move(float deltaTime) {
	coords.x += 10 * deltaTime;
	std::cout << deltaTime << std::endl;
}

void ScenePiece::setColor(char type){
	color=type;
	if(type = 'b')
		texture = CGFtexture("black.jpg");
	else
		texture = CGFtexture("white.jpg");
}

void ScenePiece::setName(int row, int column){
	this->row = row;
	this->column = column;
}