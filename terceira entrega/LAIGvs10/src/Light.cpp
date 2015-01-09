#include "Light.h"
#include <iostream>
bool Light::doublesidedLights=false;
bool Light::enabledLights=false;
bool Light::localLights=false;
int Light::lightNumber = GL_LIGHT0;
float Light::ambientLights[4]= {0.0,0.0,0.0,0.0};
Light::Light(char* id,bool enabled,string type,float* location,float* ambient,float* diffuse,float* specular,float angle,float exponent,float*direction)

{
	this->id= id;
	this->enabledLight= enabled;
	location[3]=1.0;
	glLightfv(lightNumber, GL_POSITION, location);
	glLightfv(lightNumber, GL_AMBIENT, ambient);
	glLightfv(lightNumber, GL_DIFFUSE, diffuse);
	glLightfv(lightNumber, GL_SPECULAR, specular);
	if(type=="spot")
	{
		glLightfv(lightNumber,GL_SPOT_DIRECTION,direction);
		glLightf(lightNumber,GL_SPOT_CUTOFF,angle);
		glLightf(lightNumber,GL_SPOT_EXPONENT,exponent);
	}
	glEnable(lightNumber);
	if(type=="spot")
		light = new CGFlight(lightNumber, location,direction);
	else
		light = new CGFlight(lightNumber, location);
	light->setAmbient(ambient);
	light->setDiffuse(diffuse);
	light->setSpecular(specular);
	light->disable();
	light->enable();
	lightNumber++;
}

Light::Light(char* id,bool enabled,string type,float* location,float* ambient,float* diffuse,float* specular,float angle,float exponent,float*direction,bool marker){
	this->id= id;
	this->enabledLight= enabled;
	this->marked=marked;
	location[3]=1.0;
	glLightfv(lightNumber, GL_POSITION, location);
	glLightfv(lightNumber, GL_AMBIENT, ambient);
	glLightfv(lightNumber, GL_DIFFUSE, diffuse);
	glLightfv(lightNumber, GL_SPECULAR, specular);
	if(type=="spot")
	{
		glLightfv(lightNumber,GL_SPOT_DIRECTION,direction);
		glLightf(lightNumber,GL_SPOT_CUTOFF,angle);
		glLightf(lightNumber,GL_SPOT_EXPONENT,exponent);
	}
	glEnable(lightNumber);
	if(type=="spot")
		light = new CGFlight(lightNumber, location,direction);
	else
		light = new CGFlight(lightNumber, location);
	light->setAmbient(ambient);
	light->setDiffuse(diffuse);
	light->setSpecular(specular);
	light->disable();
	light->enable();
	lightNumber++;
}

Light::~Light(void)
{
}

const float& Light::getExponent() const
{
	return exponent;
}

void Light::print() const
{
} 

void Light::setGlobalParameters(bool doublesided,bool local,bool enabled,float ambients[])
{
	Light::doublesidedLights=doublesided;
	Light::localLights=local;
	Light::enabledLights=enabled;
	copy(ambients, ambients+4, Light::ambientLights);
}

float* Light::getAmbients() {

	return ambientLights;
}


bool Light::isDoublesided() {
	return doublesidedLights;
}

bool Light::areEnabled() {
	return enabledLights;
}

bool Light::isLocal()
{
	return localLights;
}
bool Light::isEnabled() {
	return enabledLight;
}
int Light::getLastId() {
	return lightNumber;
}

void Light::enable()
{
	light->enable();
}

void Light::disable()
{
	light->disable();
}

void Light::draw()
{
	if(marked){
		light->draw();
	}
}

void Light::update()
{
	if(marked){
		light->update();
	}
}

char* Light::getId() const
{
	return id;
}

bool Light::getMarked() 
{
	return marked;
}