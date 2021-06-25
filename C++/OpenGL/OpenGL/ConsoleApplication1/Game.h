#pragma once
#include "GL/freeglut.h"
#include <iostream>
class Game
{
	int SCREEN_WIDTH = 1000,SCREEN_HEIGHT = 1000 ;
public:
	long long old_t;
	Game()
	{
		gluOrtho2D(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT);
		old_t = glutGet(GLUT_ELAPSED_TIME);
	}
	void GameWindow()
	{
		glutInitDisplayMode(GLUT_SINGLE);
		glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
		glutCreateWindow("Game");
		Init();
	}
	void Update()
	{
		old_t = glutGet(GLUT_ELAPSED_TIME);
		std::cout << (old_t / 1000.0f) << std::endl;

		draw();
	}

	void draw()
	{

	}
	
	void Init()
	{
		glClearColor(1.0f, 0.3f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	};
	~Game()
	{
		
	}

	

};


