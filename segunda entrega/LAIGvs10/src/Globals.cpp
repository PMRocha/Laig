/*
* Globals.cpp
*
*  Created on: 23/09/2013
*      Author: DEMO
*/

#include "Globals.h"
#include  <iostream>

Globals::~Globals() {
	// TODO Auto-generated destructor stub
}

void Globals::print()
{
	cout << "Globals:" << endl;
	cout << "Background color: " << background[0] << "," << background[1] << "," << background[2] << ","
		<< background[3] << endl;
	cout << "Drawmode: " << drawmode << endl;
	cout << "Shading: " << shading << endl;
	cout << "Cullface: " << cullface << endl;
	cout << "Cullorder: " << cullorder << endl;
}
Globals::Globals(float background1, float background2, float background3,
				 float background4, string drawmode, string shading, string cullface,
				 string cullorder) {
					 background= new float[4];
					 background[0]=background1;
					 background[1]=background2;
					 background[2]=background3;
					 background[3]=background4;

					 this->drawmode=setValue(drawmode);
					 this->shading=setValue(shading);
					 this->cullface=setValue(cullface);
					 this->cullorder=setValue(cullorder);
}

const float* Globals::getBackground() const {
	return background;
}


const int& Globals::getCullface() const {
	return cullface;
}

const int& Globals::getCullorder() const {
	return cullorder;
}

const int& Globals::getDrawmode() const {
	return drawmode;
}

const int& Globals::getShading() const {
	return shading;
}

int Globals::setValue(string s){
	if(s=="fill"){
		return GL_FILL;
	}else if(s=="line"){
		return GL_LINE;
	}else if(s=="point"){
		return GL_POINT;
	}else if(s=="flat"){
		return GL_FLAT;
	}else if(s=="gouraud"){
		return GL_SMOOTH;
	}else if(s=="none"){
		return GL_NONE;
	}else if(s=="back"){
		return GL_BACK;
	}else if(s=="front"){
		return GL_FRONT;
	}else if(s=="both"){
		return GL_FRONT_AND_BACK;
	}else if(s=="ccw"){
		return GL_CCW;
	}
	return GL_CW;
}