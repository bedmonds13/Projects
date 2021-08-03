
#include "GL/glut.h"
#include "Game.h"
#include "Mesh.h"


int SCREEN_WIDTH = 1420, SCREEN_HEIGHT = 1420;

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

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);	

	NewGame.Update();

	glDisable(GL_TEXTURE_2D);

	glFinish();
	glutPostRedisplay();
}

void init()
{
	gluOrtho2D(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	NewGame.Initialize();

}
void GameWindow()
{
	glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE|GLUT_RGBA);
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