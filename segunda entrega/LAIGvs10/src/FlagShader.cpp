#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "FlagShader.h"

FlagShader::FlagShader() {

}

FlagShader::FlagShader(std::string vertFile, std::string fragFile, std::string texFile) {
	init(vertFile.c_str(), fragFile.c_str());
	CGFshader::bind();

	//texture = new CGFtexture(texFile);
	std::cout << "Init shader" << std::endl;
}

void FlagShader::bind() {
	CGFshader::bind();
}

void FlagShader::unbind() {
	CGFshader::unbind();
}