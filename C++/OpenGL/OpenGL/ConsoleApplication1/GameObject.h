#pragma once
#include "Vec3.h"
#include "Texture.h"

class GameObject
{
	Vec3 position;
	Texture _sprite;
public:

	GameObject():position(Vec3::Zero()){}
	Vec3 getPosition()const
	{
		return position;
	}
	void draw()
	{
		if(!_sprite.Empty())
			_sprite.Bind();
	}
};

