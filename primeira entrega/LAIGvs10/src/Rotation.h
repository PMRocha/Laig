#ifndef ROTATION_H
#define ROTATION_H
#include "Transformation.h"
#include <string>

class Rotation :
	public Transformation
{
private:
	std::string axis;
	float angle;
public:
	Rotation(std::string axis,float angle);
	void apply();
	~Rotation(void);
};

#endif