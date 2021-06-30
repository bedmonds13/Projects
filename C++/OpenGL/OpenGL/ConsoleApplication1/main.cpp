
#include "GL/freeglut.h"
#include "Game.h"
#include <iostream>
#include "stb_image.h"
#include "Texture.h"
#include <string>


int SCREEN_WIDTH = 2000, SCREEN_HEIGHT = 1500;
Vec3 vectorTest;


Texture picleRickTexture("include/resources/png/space-background.jpg");

Game NewGame(SCREEN_WIDTH, SCREEN_HEIGHT);

void Window()
{
	glutInitWindowSize(500, 500);
}

void keyboard(unsigned char key, int mouseX , int mouseY )
{
	NewGame.Input(key, mouseX, mouseY);
}
int RandomNumberGenerator(int from, int to)
{
		srand(time(NULL));
		int num = rand() % to + from;
		return num;
}

void display()
{
	
	
	int x = SCREEN_WIDTH;
	int y = SCREEN_HEIGHT;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glEnable(GL_TEXTURE_2D);
	
	
	picleRickTexture.Bind();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(-x, -y);
		glTexCoord2f(0.0, 1.0); glVertex2f(-x, y);
		glTexCoord2f(1.0, 1.0); glVertex2f(x, y);
		glTexCoord2f(1.0, 0.0); glVertex2f(x, -y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	NewGame.Update();

	glFinish();
	glutPostRedisplay();
}

void init()
{
	gluOrtho2D(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	picleRickTexture.GenerateTexture();
	NewGame.Initialize();
}
void GameWindow()
{
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Game");	
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	GameWindow();
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
