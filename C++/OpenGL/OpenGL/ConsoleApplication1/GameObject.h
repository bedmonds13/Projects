#pragma once
#include "Vec3.h"
#include <iostream>
#include <string>
#include "Texture.h"

class GameObject
{
	Vec3 position;
public:
	Texture objectTexture;

	GameObject():objectTexture() {
	}
	Vec3 getPosition()const
	{
		return position;
	}
	void render(int x , int y)
	{
		objectTexture.Bind();
		
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(-x, -y);
			glTexCoord2f(0.0, 1.0); glVertex2f(-x, y);
			glTexCoord2f(1.0, 1.0); glVertex2f(x, y);
			glTexCoord2f(1.0, 0.0); glVertex2f(x, -y);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
	}
};

