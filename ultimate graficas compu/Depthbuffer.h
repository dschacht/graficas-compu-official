#pragma once
#pragma once
#include <IL/il.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>


class Depthbuffer
{
public:
	Depthbuffer();
	~Depthbuffer();

	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();

private:
		GLuint _framebuffer;
		GLuint _depthmap;
		GLsizei _resolution;

};

