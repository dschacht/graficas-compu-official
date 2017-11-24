#include "Mesh.h"
#include <iostream>



Mesh::Mesh()
{
	_vertexCount = 0;
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_indicesBufferObject = 0;
	_indicesCount = 0;
	_normalBufferObject = 0;
	_texCoordsVertexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);

	_vertexCount = 0;

}

void Mesh::CreateMesh(GLint vertexCount)
{
	glGenVertexArrays(1, &_vertexArrayObject);
	_vertexCount = vertexCount;
}

void Mesh::Draw(GLenum primitive)
{

	if (_indicesCount > 0)
	{
		glBindVertexArray(_vertexArrayObject);
		glDrawElements(primitive, _indicesCount, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
	else {
		glBindVertexArray(_vertexArrayObject);
		glDrawArrays(primitive, 0, _vertexCount);
		glBindVertexArray(0);
	}

}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() == _vertexCount)
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2)* positions.size(), positions.data(), usage, locationIndex, 2);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() == _vertexCount)
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3)* positions.size(), positions.data(), usage, locationIndex, 3);
}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{

	if (colors.size() > 0 && colors.size() == _vertexCount)
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3)* colors.size(), colors.data(), usage, locationIndex, 3);
}

void Mesh::SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex)
{

	if (colors.size() > 0 && colors.size() == _vertexCount)
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec4)* colors.size(), colors.data(), usage, locationIndex, 3);
}

void Mesh::SetIndices(std::vector<unsigned int> indices, GLenum usage)
{
	if (indices.size() <= 0)
		return;

	_indicesCount = indices.size();

	if (_indicesBufferObject != 0)
		glDeleteBuffers(1, &_indicesBufferObject);


	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(1, &_indicesBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) *indices.size(), indices.data(), usage);

	glBindVertexArray(0);


}

void Mesh::SetNormalAttribute(std::vector<glm::vec3> normal, GLenum usage, GLuint locationIndex)
{
	if (normal.size() > 0 && normal.size() == _vertexCount) {
		SetAttributeData(_normalBufferObject, sizeof(glm::vec3)* normal.size(), normal.data(), usage, locationIndex, 3);
	}

}

void Mesh::SetTexCoordAttribute(std::vector<glm::vec2> texCoords, GLenum usage, GLuint locationIndex)
{
	if (texCoords.size() > 0 && texCoords.size() == _vertexCount) {
		SetAttributeData(_texCoordsVertexBufferObject, sizeof(glm::vec2)* texCoords.size(),
			texCoords.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (buffer)
		glDeleteBuffers(1, &buffer);

	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0);
}

