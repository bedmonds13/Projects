#include "Ball.h"
#include <cstdlib>

using namespace std;
Ball::Ball()
{
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;

}
Ball::Ball(int pos_x, int pos_y)
{
	x = pos_x;
	y = pos_y;
	dx = 0;
	dy = 0;
}

int Ball::get_position_x()
{
	return x;
}
int Ball::get_position_y()
{
	return y;
}
int Ball::get_velocity_x() 
{
	return dx;
}
int Ball::get_velocity_y()
{
	return dy;
}
void Ball::set_velocity_x(int new_v) { dx = new_v; }
void Ball::set_velocity_y(int new_v) { dy = new_v; }
void Ball::move()
{
	x += dx;
	y += dy;
}
void Ball::draw(int num_segments, int r)
{
	glColor3f(1.0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float line_x = r * cosf(theta);//calculate the x component
		float line_y = r * sinf(theta);//calculate the y component

		glVertex2f(x + line_x, y + line_y);//output vertex
	}

	glEnd();
}