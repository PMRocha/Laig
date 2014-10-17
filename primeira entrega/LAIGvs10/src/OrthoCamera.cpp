/*
 * OrthoCamera.cpp
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#include "OrthoCamera.h"



float OrthoCamera::getBottom() const {
	return bottom;
}

float OrthoCamera::getFar() const {
	return far;
}


float OrthoCamera::getLeft() const {
	return left;
}

float OrthoCamera::getNear() const {
	return near;
}

float OrthoCamera::getRight() const {
	return right;
}

float OrthoCamera::getTop() const {
	return top;
}

OrthoCamera::~OrthoCamera() {
	// TODO Auto-generated destructor stub
}

OrthoCamera::OrthoCamera( float near, float far, float left,
		float right, float top, float bottom,bool activated)
{
	this->near=near;
	this->far=far;
	this->left=left;
	this->right=right;
	this->top=top;
	this->bottom=bottom;
}


void OrthoCamera::applyView()
{
	glOrtho(left,right,bottom,top,near,far);
}
