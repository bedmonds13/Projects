
#include "GL/glut.h"
#include "Game.h"
#include <iostream>
#include "stb_image.h"
#include "Texture.h"
#include <string>

using namespace std;

int SCREEN_WIDTH = 2000, SCREEN_HEIGHT = 1500;
static Game NewGame;


static Texture picleRickTexture("include/resources/png/mangekyo-sharingan.png");

void Window()
{
	glutInitWindowSize(500, 500);
}

void keyboard(unsigned char key, int mouseX , int mouseY )
{
	if (key == 27)
		exit(0);
}
int RandomNumberGenerator(int from, int to)
{
		srand(time(NULL));
		int num = rand() % to + from;
		return num;
}

void display()
{
	NewGame.Update();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glEnable(GL_TEXTURE_2D);
	//glColor3f(0, 1.0f, 0);
	
	int x = SCREEN_WIDTH/2;
	int y = SCREEN_HEIGHT/2;
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(-x, -y);
		glTexCoord2f(0.0, 1.0); glVertex2f(-x, y);
		glTexCoord2f(1.0, 1.0); glVertex2f(x, y);
		glTexCoord2f(1.0, 0.0); glVertex2f(x, -y);
	glEnd();

	glFinish();
	glutPostRedisplay();
}



void init()
{
	gluOrtho2D(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	NewGame.old_t  = glutGet(GLUT_ELAPSED_TIME);

	picleRickTexture.GenerateTexture();
	

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
