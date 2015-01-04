/*
 * PerspectiveCamera.h
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#ifndef PERSPECTIVECAMERA_H_
#define PERSPECTIVECAMERA_H_
#include "CGFcamera.h"
#include "GL/glui.h"
#include "GL/glut.h"
class PerspectiveCamera : public CGFcamera {
private:
	float nearF,farF,angle;
	float position[3],target[3];
public:
	PerspectiveCamera(bool activated,float near,float far,float angle,float positionX,float positionY,float positionZ,float targetX,float targetY,float targetZ);
	void print() const;
	float getAngle() const;
	float getFar() const;
	float getNear() const;
	void applyView();
	friend class TPinterface;
};

#endif /* PERSPECTIVECAMERA_H_ */
