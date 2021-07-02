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
	}
};

