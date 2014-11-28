#ifndef TRANSLATION_H
#define TRANSLATION_H
#include "Transformation.h"
class Translation :
	public Transformation
{
private:
	float x,y,z;
public:
	Translation(float x,float y, float z);
	void apply();
	~Translation(void);
};

#endif