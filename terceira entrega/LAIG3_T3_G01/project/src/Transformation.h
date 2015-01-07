#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "glui.h"
class Transformation
{
public:
	Transformation(void);
	virtual void apply();
	~Transformation(void);
};

#endif