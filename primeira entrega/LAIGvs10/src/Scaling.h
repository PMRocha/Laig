#ifndef SCALING_H
#define SCALING_H
#include "transformation.h"
class Scaling :
	public Transformation
{
private:
	float x,y,z;
public:
	Scaling(float x,float y, float z);
	~Scaling(void);
	void apply();
};

#endif