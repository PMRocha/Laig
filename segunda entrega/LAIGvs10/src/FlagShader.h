#ifndef FLAGSHADER_H
#define FLAGSHADER_H

#include <string>

#include "CGFshader.h"
#include "CGFtexture.h"

class FlagShader : public CGFshader{
public:
	FlagShader();
	FlagShader(std::string vertFile, std::string fragFile, std::string texFile);
	void bind();
private:
	CGFtexture* texture;
};

#endif