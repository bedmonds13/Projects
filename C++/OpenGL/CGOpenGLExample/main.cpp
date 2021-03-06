#include "GL/freeglut.h"
#include "GameTime.h"
#include "Ball.h";

using namespace std;

const int SCREEN_WIDTH = 50;
const int SCREEN_HEIGHT = 50;
int x = 0;
int y = 0;
int vx = 0;
int vy = 0;

const int BALLSPEED = 2;
Time GAME_TIME = Time();
Time NEXT_FRAME = GAME_TIME;
Ball game_ball = Ball(30, 10);
int ball_radius = 4;

void Window()
{
	glutInitWindowSize(500, 500);
}
void keyboard(unsigned char key, int mouseX , int mouseY )
{
	switch (key) {
		case 'w':
			y++;
			break;
		case 's':
			y--;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}
int RandomDirection()
{
		srand(time(0));
		int num = rand() % 3 + (-1);
		return num;
}
void Initialize()
{
	glPointSize(2.0);
	gluOrtho2D(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT);
	glClearColor(0.2,0.3,0.1,0.2);
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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawbox(x,y);
	game_ball.draw(20, ball_radius);
	glFlush();

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	Window();
	glutCreateWindow("Game");
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	Initialize();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutTimerFunc(1000/30, Update, 0);
	glutMainLoop();

	return 0;
}