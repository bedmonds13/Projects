#pragma once
#include "GL/freeglut.h"
#include <iostream>
class Game
{
public:
	long long old_t;
	
	Game()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
	}
	void Update()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
		std::cout << (old_t / 1000.0f) << std::endl;

		draw();
	}

	void draw(){}
	
	~Game(){		}
};


