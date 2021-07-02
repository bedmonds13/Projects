#pragma once
#include "GL/freeglut.h"
#include "Ball.h"
#include <iostream>
#include "Texture.h"
class Game
{
	Texture background;
	Ball gameBall;
	int boundary_x;
	int boundary_y;
public:
	long long old_t;

	Game() : background(Texture("include/resources/png/space-background.jpg")), boundary_x(500), boundary_y(500), old_t(glutGet(GLUT_ELAPSED_TIME)) {}
	Game(int x, int y):background(Texture("include/resources/png/space-background.jpg")), boundary_x(x),boundary_y(y), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	
	void Initialize()
	{
		gameBall.objectTexture.GenerateTexture();
		background.GenerateTexture();
	}

	void Update()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
		draw();
	}

	void draw(){

		background.Bind();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(-boundary_x, -boundary_y);
		glTexCoord2f(0.0, 1.0); glVertex2f(-boundary_x, boundary_y);
		glTexCoord2f(1.0, 1.0); glVertex2f(boundary_x, boundary_y);
		glTexCoord2f(1.0, 0.0); glVertex2f(boundary_x, -boundary_y);
		glEnd(); 
		gameBall.render(500, 500);
	}
	void Input(unsigned char key, int mouseX, int mouseY)
	{
		if (key == 27)
			exit(0);
	}
	void drawBackground()
	{
	}
	
	~Game() { }
};


