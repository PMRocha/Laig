/*
 * OrthoCamera.h
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#ifndef ORTHOCAMERA_H_
#define ORTHOCAMERA_H_
#include "glui.h"
#include "glut.h"
#include "CGFcamera.h"
class OrthoCamera : public CGFcamera {
private:
	float nearF, farF, leftF, rightF, topF, bottomF;
public:
	OrthoCamera(float near,float far,float left,float right,float top,float bottom,bool activated);
	virtual ~OrthoCamera();
	float getBottom() const;
	float getFar() const;
	float getLeft() const;
	float getNear() const;
	float getRight() const;
	float getTop() const;
	void print() const;
	void applyView();
	friend class TPinterface;
};

#endif /* ORTHOCAMERA_H_ */
