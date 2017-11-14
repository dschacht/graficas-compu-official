#include "Texture2D.h"
#include <IL/il.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>




Texture2D::Texture2D()
{
	_textureID = 0;
}


Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_textureID);
}

void Texture2D::Loadtexture(std::string path)
{

	ILuint imageID;

	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage(path.c_str());

	
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER
		, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S
		, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT),
			ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
			0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE),
			ilGetData());

		ilBindImage(0);
		ilDeleteImages(1, &imageID);




}

void Texture2D::Bind()
{
	glBindTexture(GL_TEXTURE_2D, _textureID);
}

void Texture2D::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);

}
