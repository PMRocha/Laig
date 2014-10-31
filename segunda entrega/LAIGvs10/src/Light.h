#ifndef LIGHTS_H
#define LIGHTS_H
#include "CGFlight.h"
using namespace std;
class Light 
{
private:
	static bool doublesidedLights,localLights,enabledLights;
	static float ambientLights[4];
	static int lightNumber;
	char* id;
	string type;
	bool enabledLight,marked;
	float exponent;
	CGFlight* light;
public:
	Light(char* id,bool enabled,string type,float* location,float* ambient,float* diffuse,float* specular,float angle,float exponent,float*direction);
	Light(char* id,bool enabled,string type,float* location,float* ambient,float* diffuse,float* specular,float angle,float exponent,float*direction,bool marker);
	~Light(void);
	char* getId() const;
	const float& getExponent() const;
	static void setGlobalParameters(bool doublesided,bool local,bool enabled,float ambients[]);
	static float* getAmbients() ;
	static bool isDoublesided() ;
	static bool areEnabled() ;
	static bool isLocal() ;
	void print() const;
	bool isEnabled();
	static int getLastId() ;
	void enable();
	void disable();
	void draw();
	void update();
};

#endif
