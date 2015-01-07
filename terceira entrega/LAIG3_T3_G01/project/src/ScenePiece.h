#ifndef _SCENEPIECE_H_
#define _SCENEPIECE_H_
#include "SceneObject.h"
#include "ScenePlane.h"
#include "SceneCylinder.h"
#include "CGFtexture.h"
using namespace std;

class ScenePiece:public SceneObject
{
private:
	SceneCylinder piece;
	Point coords;
	char color;
	int row, column;
	CGFtexture texture;
public:
	ScenePiece(double x, double y, double z);
	~ScenePiece(void);
	void draw(void);
	void setColor(char type);
	void move(float deltaTime);
	void setName(int row, int column);
};

#endif