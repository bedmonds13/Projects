#include "GL/glut.h"
#include "Ball.h";
#include "Game.h"
#include <iostream>
#include "stb_image.h"

using namespace std;

/*
int x = 0;
int y = 0;
int vx = 0;
int vy = 0;

const int BALLSPEED = 2;

Ball game_ball = Ball(30, 10);
int ball_radius = 4;
*/
Game* NewGame = new Game();


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
	NewGame->Update();


	glFinish();
	glutPostRedisplay();
}


void init()
{
	NewGame->old_t  = glutGet(GLUT_ELAPSED_TIME);
}


int main(int argc, char* argv[])
{
	
	init();
	glutInit(&argc, argv);
	NewGame->GameWindow();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
/*
void Initialize()
{
	
	while (game_ball.get_velocity_x() == 0 && game_ball.get_velocity_y() == 0)
	{
		game_ball.set_velocity_x(BALLSPEED * RandomDirection());
		game_ball.set_velocity_y(BALLSPEED * RandomDirection());
	}

}

void Update(int)
{
	if (game_ball.get_position_x() >= SCREEN_WIDTH ||
		game_ball.get_position_x() <= -SCREEN_WIDTH )
		game_ball.set_velocity_x(-(game_ball.get_velocity_x()));
	if (game_ball.get_position_y() >= SCREEN_HEIGHT ||
		game_ball.get_position_y() <= -SCREEN_HEIGHT)
		game_ball.set_velocity_y(-(game_ball.get_velocity_y()));

	if (abs(game_ball.get_position_x() - x) < ball_radius && abs(game_ball.get_position_y() - y) < ball_radius)
	{
		game_ball.set_velocity_x(RandomDirection());
		game_ball.set_velocity_y(RandomDirection());
	}


	game_ball.move();
	glutPostRedisplay();
	glutTimerFunc(1000/30, Update, 0);
	
}


void drawbox(int x, int y) 
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(-1+x,-1+y);
		glVertex2i(-1+x,1+y);
		glVertex2i(1+x,1+y);
		glVertex2i(1+x,-1+y);
	glEnd();
}
*/