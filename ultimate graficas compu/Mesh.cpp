#include "Mesh.h"
#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>


Mesh::Mesh()
{
	_vertexArrayObject =0;
	_positionsVertexBufferObject =0;
	_colorsVertexBufferObject =0;
    _vertexCount =0;
}



Mesh::~Mesh()
{
}
