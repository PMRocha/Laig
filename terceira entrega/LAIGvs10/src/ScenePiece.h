#ifndef _SCENEPIECE_H_
#define _SCENEPIECE_H_
#include "SceneObject.h"
#include "ScenePlane.h"
#include "SceneCylinder.h"
using namespace std;

class ScenePiece:public SceneObject
{
private:
	SceneCylinder piece;
	Point coords;
public:
	ScenePiece(double x, double y, double z);
	~ScenePiece(void);
	void draw(void);
};

#endif