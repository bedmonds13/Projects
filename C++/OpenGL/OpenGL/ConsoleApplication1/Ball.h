#pragma once
#include <time.h>
#include "GL/glut.h";
class Ball
{
public:
	Ball();
	Ball(int pos_x, int pos_y);
	int get_position_x();
	int get_position_y();
	int get_velocity_x();
	int get_velocity_y();
	void set_velocity_x(int new_v);
	void set_velocity_y(int new_v);
	void move();
	void draw(int Num_segments, int r);
private:
	int x;
	int y;
	int dx;
	int dy;
};

