#pragma once
#include "GL/glut.h"
#include"stb_image.h"
#include <string>
#include <time.h>

class Texture
{
	int width, height, nrChannels;
	GLubyte* data;
	std::string filePath;
	GLuint* id;
public:

	Texture() :width(0), height(0), nrChannels(0), filePath("include/resources/png/mangekyo-sharingan.png"), data(nullptr) 
	{	
		id = new GLuint;
		stbi_set_flip_vertically_on_load(1);
		data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
	}

	Texture(std::string&& newPath):width(0), height(0), nrChannels(0), filePath(newPath)
	{
		id = new GLuint;
		stbi_set_flip_vertically_on_load(1);
		data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
	}



	void GenerateTexture()
	{
		if (data)
		{
			glGenTextures(1, id);
			glBindTexture(GL_TEXTURE_2D, id[0]);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
		
		}
		stbi_image_free(data);
	}


	void Bind()
	{
		if(id)
			glBindTexture(GL_TEXTURE_2D, id[0]);
	}

	~Texture()
	{
		if(id)
			glDeleteTextures(0, id);
	}

	GLuint* get_ID()
	{
		return id;
	}

};

