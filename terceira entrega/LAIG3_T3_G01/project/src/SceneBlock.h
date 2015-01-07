#ifndef _SCENEBLOCK_H_
#define _SCENEBLOCK_H_
#include "SceneObject.h"
#include "ScenePlane.h"
using namespace std;

class SceneBlock:public SceneObject
{
private:
	ScenePlane rec1;
public:
	SceneBlock();
	~SceneBlock(void);
	void draw(void);
};

#endif