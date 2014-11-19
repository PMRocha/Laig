#include "SceneFlag.h"

SceneFlag::SceneFlag() :
	plane(100)
{

}

SceneFlag::SceneFlag(std::string texture) :
	plane(100),
	shader("flag.vert", "flag.frag", texture)
{
	std::cout << "Shader intialized." << std::endl;
}

void SceneFlag::draw() {

	shader.bind();

	plane.draw();

	shader.unbind();
}