/*
* Cameras.h
 *
 *  Created on: 23/09/2013
 *      Author: DEMO
 */

#ifndef CAMERAS_H_
#define CAMERAS_H_
#include "tinyxml.h"
#include <string>
#include <iostream>
#include "CGFscene.h"
class Camera {
protected:
	bool activated;
public:
	virtual ~Camera();
	Camera(bool activated);
	virtual void applyView() = 0;
};

#endif /* CAMERAS_H_ */
