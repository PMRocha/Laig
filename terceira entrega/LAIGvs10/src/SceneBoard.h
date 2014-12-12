#ifndef _SCENEBOARD_H_
#define _SCENEBOARD_H_
#include "SceneObject.h"
#include "ScenePlane.h"
#include "SceneBlock.h"
using namespace std;

class SceneBoard:public SceneObject
{
private:
	SceneBlock block;
public:
	SceneBoard();
	~SceneBoard(void);
	void draw(void);
};

#endif