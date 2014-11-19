#include "FlagShader.h"

FlagShader::FlagShader() {

}

FlagShader::FlagShader(std::string vertFile, std::string fragFile, std::string texFile) {
	init(
	texture = new CGFtexture(texFile);
}

void FlagShader::bind() {
	CGFshader::bind();
}