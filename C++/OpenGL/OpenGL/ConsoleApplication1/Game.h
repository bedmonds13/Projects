#pragma once
#include "GL/freeglut.h"
#include <iostream>
class Game
{
	int SCREEN_WIDTH = 1000,SCREEN_HEIGHT = 1000 ;
	float old_t;
public:
	Game()
	{
		gluOrtho2D(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT);
		GameWindow();
		old_t = glutGet(GLUT_ELAPSED_TIME);
	}
	void GameWindow()
	{
		glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
		glutCreateWindow("Game");
		Init();
	}
	void Start()
	{
		glutDisplayFunc(Render);
		glutMainLoop();
	}
	void Update()
	{
	}
	
	static void Render()
	{
		//Update();
		//glFlush;
		glutSwapBuffers();
		
	}
	void Init()
	{
		glClearColor(1.0f, 0.3f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	};

	

};


