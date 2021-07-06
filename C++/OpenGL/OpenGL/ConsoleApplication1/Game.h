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

	std::vector<Texture> Textures;
public:
	long long old_t;

	Game() : background(Texture("include/resources/png/space-background.jpg")), screen_boundary_x(500), screen_boundary_y(500), old_t(glutGet(GLUT_ELAPSED_TIME)){}
	Game(int x, int y):background(Texture("include/resources/png/space-background.jpg")),secondTexture("include/resources/png/sharingan2-edit.png"), screen_boundary_x(x),screen_boundary_y(y), old_t(glutGet(GLUT_ELAPSED_TIME))
	{
		Textures.push_back(background);
		Textures.push_back(secondTexture);
	}
	
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
		glTexCoord2f(0.0, 0.0); glVertex2f(-screen_boundary_x, -screen_boundary_y);
		glTexCoord2f(0.0, 1.0); glVertex2f(-screen_boundary_x, screen_boundary_y);
		glTexCoord2f(1.0, 1.0); glVertex2f(screen_boundary_x, screen_boundary_y);
		glTexCoord2f(1.0, 0.0); glVertex2f(screen_boundary_x, -screen_boundary_y);
		glEnd();
		
		secondTexture.Bind();
		glEnable(GL_BLEND);
		int x = screen_boundary_x / 5;
		int y = screen_boundary_y / 5;
		float depth = 0.1f;

		glBlendFunc(GL_ONE, GL_ONE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-x, -y, depth);
		glTexCoord2f(0.0, 1.0); glVertex3f(-x, y, depth);
		glTexCoord2f(1.0, 1.0); glVertex3f(x, y, depth);
		glTexCoord2f(1.0, 0.0); glVertex3f(x, -y,depth);
		glEnd();
		glDisable(GL_BLEND);
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


