#ifndef FLAGSHADER_H
#define FLAGSHADER_H

#include <iostream>
#include <string>

#include "CGFshader.h"
#include "CGFtexture.h"

class FlagShader : public CGFshader{
public:
	FlagShader();
	FlagShader(std::string vertFile, std::string fragFile, std::string texFile);
	void bind();
	void unbind();
private:
	CGFtexture* texture;

	int imageLoc;
};

#endif