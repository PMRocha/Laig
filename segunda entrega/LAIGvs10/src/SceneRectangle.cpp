#include "SceneRectangle.h"


SceneRectangle::SceneRectangle(void)
{
}

SceneRectangle::SceneRectangle(float xi,float yi, float xf, float yf)
{
	SceneObject();

	this->xi=xi;
	this->xf=xf;
	this->yi=yi;
	this->yf=yf;

	comp=abs(xf-xi);
	larg=abs(yf-yi);
}

void SceneRectangle::draw()
{

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0,0);
		glNormal3f(0,0,1);
		glVertex3f( xi, yi, 0);

		glTexCoord2f(comp/(float)textS,0);
		glNormal3f(0,0,1);
		glVertex3f( xf, yi, 0);

		glTexCoord2f(comp/(float)textS,larg/(float)textT);
		glNormal3f(0,0,1);
		glVertex3f( xf, yf, 0);

		glTexCoord2f(0,larg/(float)textT);
		glNormal3f(0,0,1);
		glVertex3f( xi, yf, 0); 
	}
	glEnd();
}

void SceneRectangle::setTextS(float s)
{
	textS=s;

}
	
void SceneRectangle::setTextT(float t)
{
	textT=t;
}


SceneRectangle::~SceneRectangle(void)
{

}
