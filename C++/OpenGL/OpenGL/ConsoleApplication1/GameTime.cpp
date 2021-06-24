#include <ctime>
#include "GameTime.h";

using namespace std;
Time::Time()
{
	time_t now = time(nullptr);
	//my_time = *localtime(&now);
}
tm Time::get_time()
{
	return my_time;
}
tm Time::add_seconds(int time)
{
	my_time.tm_sec += time;
	return my_time;
}
Time Time::operator=(const Time& right_side)
{
	this->my_time = right_side.my_time;
	return *this;
}
bool Time::operator<=(const Time& right_side)
{
	if (my_time.tm_sec <= right_side.my_time.tm_sec)
	{
		return true;
	}
	else
		return false;
}
