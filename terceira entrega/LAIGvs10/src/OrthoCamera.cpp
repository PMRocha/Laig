/*
 * OrthoCamera.cpp
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#include "OrthoCamera.h"



float OrthoCamera::getBottom() const {
	return bottomF;
}

float OrthoCamera::getFar() const {
	return farF;
}


float OrthoCamera::getLeft() const {
	return leftF;
}

float OrthoCamera::getNear() const {
	return nearF;
}

float OrthoCamera::getRight() const {
	return rightF;
}

float OrthoCamera::getTop() const {
	return topF;
}

OrthoCamera::~OrthoCamera() {
	// TODO Auto-generated destructor stub
}

OrthoCamera::OrthoCamera( float near, float far, float left,
		float right, float top, float bottom,bool activated)
{
	this->nearF=near;
	this->farF=far;
	this->leftF=left;
	this->rightF=right;
	this->topF=top;
	this->bottomF=bottom;
}


void OrthoCamera::applyView()
{
	glOrtho(leftF,rightF,bottomF,topF,nearF,farF);
}
