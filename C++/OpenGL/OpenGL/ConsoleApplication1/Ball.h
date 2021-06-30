#pragma once
#include <time.h>
#include "GL/glut.h";
#include "GameObject.h"
class Ball: public GameObject
{
	int radius;
public:
	Ball() : radius(400){};
	void draw(int Num_segments);
	
};

