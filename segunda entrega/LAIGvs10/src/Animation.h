#ifndef ANIMATION_H
#define ANIMATION_H
#include <string>
#include "Point.h"
class Animation
{
private:
	float span;
	float hip;
	float angle;
	Point lastPoint;
	Point currentPoint;
	Point deltaPoint;
	vector<Point> controlpoints;
	string type;
	int index;
	float acum;
	float timeDivided;
	bool animAngle;
	float deltaAngle;
	float lastAngle;
	unsigned long lastTime;
public:
	Animation(void);
	Animation(float span,std::string type, vector<Point> controlpoints);
	Animation(float span,std::string type, float centerX, float centerY, float centerZ, float radius, float startang, float rotang );
	~Animation(void);
	void print();
	void movement();
	void update(unsigned long time);
};
#endif
