#pragma once
#include <string>
#include <vector>
class Person
{
	std::string name;
	Person* bestFriend;
	int popularityCounter;
	int age;

public:
	Person()
	{
		name = "";
		bestFriend = nullptr;
		popularityCounter = 0;
		age = 0;
	}
	Person(std::string newName) :name{ newName }, bestFriend{ nullptr }, popularityCounter{ 0 }, age{ 0 }{}
	Person(std::string newName, int newAge) :name{ newName }, bestFriend{ nullptr }, popularityCounter{ 0 }, age{ newAge }{}

	std::string get_name();
	
	std::string get_bestfriend();
	
	void set_bestfriend(Person* newBestFriend);

	void increment_popularity();
	int get_popularity();
	
	void increment_age();
	
	int get_age();
	
	
};

