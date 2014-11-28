/*
 * Globals.h
 *
 *  Created on: 23/09/2013
 *      Author: João Nadais
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <string>
#include <GL/glut.h>
using namespace std;
class Globals {
private:
	float* background;
	int drawmode,shading,cullface,cullorder;
public:
	Globals(float background1,float background2,float background3,float background4,string drawmode,string shading,	string cullface,string cullorder);
	virtual ~Globals();
	const int& getCullface() const;
	const int& getCullorder() const;
	const int& getDrawmode() const;
	const int& getShading() const;
	const float* getBackground() const;
	int setValue(string s);
	void apply();
	void print();
};

#endif /* GLOBALS_H_ */
