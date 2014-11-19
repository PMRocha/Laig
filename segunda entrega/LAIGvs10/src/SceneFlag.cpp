#include "SceneFlag.h"

SceneFlag::SceneFlag() :
	plane(0)
{

}

SceneFlag::SceneFlag(std::string texture) :
	plane(0)
{
	/*apply texture? idk... */
}

void SceneFlag::draw() {
	plane.draw();
}