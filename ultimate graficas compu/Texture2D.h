#pragma once
#include <IL/il.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>


class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	void Loadtexture(std::string path);
	void Bind();
	void Unbind();


private:
	GLuint _textureID;
};

