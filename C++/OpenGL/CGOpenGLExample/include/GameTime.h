#pragma once
#include <ctime>
class Time
{
public:
	Time();
	Time operator=(const Time&);
	bool operator<=(const Time&);
	tm get_time();
	tm add_seconds(int time);

private:
	tm my_time;
};

