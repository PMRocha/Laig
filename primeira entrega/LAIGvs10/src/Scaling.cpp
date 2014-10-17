#include "Scaling.h"


Scaling::Scaling(float x,float y, float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}	


Scaling::~Scaling(void)
{
}

void Scaling::apply()
{
	glScalef(x,y,z);
}
