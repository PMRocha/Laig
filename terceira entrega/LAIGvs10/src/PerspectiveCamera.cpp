/*
 * PerspectiveCamera.cpp
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#include "PerspectiveCamera.h"

float PerspectiveCamera::getAngle() const {
	return angle;
}

float PerspectiveCamera::getFar() const {
	return far;
}

float PerspectiveCamera::getNear() const {
	return near;
}


PerspectiveCamera::PerspectiveCamera(bool activated,float near, float far,
		float angle, float positionX, float positionY, float positionZ,
		float targetX, float targetY, float targetZ)
{
	this->position[0]=positionX;
	this->position[1]=positionY;
	this->position[2]=positionZ;
	this->target[0]=targetX;
	this->target[1]=targetY;
	this->target[2]=targetZ;
	this->near=near;
	this->far=far;
	this->angle=angle;
}

void PerspectiveCamera::applyView()
{
	gluPerspective(angle,glutGet(GLUT_WINDOW_WIDTH)/glutGet(GLUT_WINDOW_HEIGHT),near,far);
	gluLookAt(position[0],position[1],position[2],target[0],target[1],target[2],0,1,0);
}