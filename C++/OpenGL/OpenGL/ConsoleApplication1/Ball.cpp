#include "Ball.h"
#include <cstdlib>
#include <iostream>
void Ball::draw(int num_segments)
{
	glColor3f(1.0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float line_x = radius * cosf(theta);//calculate the x component
		float line_y = radius * sinf(theta);//calculate the y component

		glVertex2f( getPosition().x() + line_x, getPosition().y() + line_y);//output vertex
	}
	glEnd();
}