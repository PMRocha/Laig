#include "Rotation.h"

Rotation::Rotation(std::string axis,float angle)
{
	this->axis=axis;
	this->angle=angle;
}


Rotation::~Rotation(void)
{
}

void Rotation::apply()
{
	if(axis=="x")
		glRotatef(angle,1,0,0);
	else if(axis=="y")
		glRotatef(angle,0,1,0);
	else if(axis=="z")
		glRotatef(angle,0,0,1);
}
