#ifndef SCENEFLAG_H
#define SCENEFLAG_H

#include <string>
#include "SceneObject.h"
#include "ScenePlane.h"

class SceneFlag : public SceneObject {
public:
	SceneFlag();
	SceneFlag(std::string texture);
	void draw();
private:
	ScenePlane plane;
};

#endif