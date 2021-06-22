#include "Person.h"
#include <vector>
#include <string>


	std::string Person::get_name()
	{
		return name;
	}
	std::string Person::get_bestfriend()
	{
		return bestFriend->get_name();
	}
	void Person::set_bestfriend(Person* newBestFriend)
	{
		bestFriend = newBestFriend;
	}
	void Person::increment_popularity()
	{
		popularityCounter++;
	}
	int Person::get_popularity()
	{
		return popularityCounter;
	}
	void Person::increment_age()
	{
		age++;
	}
	int Person::get_age()
	{
		return age;
	}

	