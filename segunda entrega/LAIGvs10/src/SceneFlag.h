#ifndef SCENEFLAG_H
#define SCENEFLAG_H

#include <string>
#include "SceneObject.h"

class SceneFlag : public SceneObject {
public:
	SceneFlag();
	SceneFlag(std::string texture);
	void draw();
private:

};

#endif