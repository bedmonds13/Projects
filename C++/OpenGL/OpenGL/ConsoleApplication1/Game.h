#pragma once
#include <vector>
#include "GL/Glut.h"
#include "Ball.h"
#include "Texture.h"
class Game
{
	Texture background;
	Texture secondTexture;

	int screen_boundary_x;
	int screen_boundary_y;

	float rotation = 0;

public:
	long long old_t;

	Game() : background(Texture("include/resources/png/space-background.jpg")), screen_boundary_x(500), screen_boundary_y(500), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	Game(int x, int y):background(Texture("include/resources/png/red-space.png")),secondTexture("include/resources/png/sharingan2-edit.png"), screen_boundary_x(x),screen_boundary_y(y), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	
	void Initialize()
	{
		background.GenerateTexture();
		secondTexture.GenerateTexture();
	}

	void Update()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
		draw();
	}

	void draw()
	{
		
		background.Bind();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(-screen_boundary_x/2, -screen_boundary_y/2);
		glTexCoord2f(0.0, 1.0); glVertex2f(-screen_boundary_x/2, screen_boundary_y/2);
		glTexCoord2f(1.0, 1.0); glVertex2f(screen_boundary_x/2, screen_boundary_y/2);
		glTexCoord2f(1.0, 0.0); glVertex2f(screen_boundary_x/2, -screen_boundary_y/2);
		glEnd();
		
		
	

		secondTexture.Bind();
		int x = screen_boundary_x / 5;
		int y = screen_boundary_y / 5;
		
		glPushMatrix();
		glRotatef(rotation,0,0,1);
		rotation += (1.0f/1000.0f);

		float depth = 0.1f;
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.5, 1, 0.5, 0.5);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-x, -y, depth);
		glTexCoord2f(0.0, 1.0); glVertex3f(-x, y, depth);
		glTexCoord2f(1.0, 1.0); glVertex3f(x, y, depth);
		glTexCoord2f(1.0, 0.0); glVertex3f(x, -y,depth);
		glEnd();
		glPopMatrix();

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		
	}
	void Input(unsigned char key, int mouseX, int mouseY)
	{
		if (key == 27)
			exit(0);
	}
	void drawBackground(){}
	
	~Game() { }
};


