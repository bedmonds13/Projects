#pragma once
#include "GL/freeglut.h"
#include "Ball.h"
#include <iostream>
class Game
{
	Ball gameBall;
	int boundary_x;
	int boundary_y;
public:
	long long old_t;

	Game() : boundary_x(500), boundary_y(500), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	Game(int x, int y): boundary_x(x),boundary_y(y), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	
	void Initialize()
	{
		gameBall.objectTexture.GenerateTexture();
	}
	void Update()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
		draw();
	}

	void draw(){
		gameBall.render(500, 500);
		gameBall.draw(400);
	}
	void Input(unsigned char key, int mouseX, int mouseY)
	{
		if (key == 27)
			exit(0);
	}
	
	~Game() { }
};


