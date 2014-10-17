#include "Translation.h"


Translation::Translation(float x,float y, float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

Translation::~Translation(void)
{
}

void Translation::apply()
{
	glTranslatef(x,y,z);
}
