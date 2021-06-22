#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include "Person.h"
#include "Car.h"





void RunBestFriendDistributor()
{
	std::vector<Person*> people;

	int n = 0;
	while (n != -1)
	{
		std::string name;
		std::cout << "Add person :\n";
		std::cin >> name;
		Person* newPerson = new Person(name);
		people.push_back(newPerson);


		std::cout << "Would you like to add more? Enter -1 to quit :\n";
		std::cin >> n;
	}

	std::cout << "Listed people: ";

	for (int i = 0; i < people.size(); i++)
	{
		std::cout << people[i]->get_name() + " ";
	}
	std::cout << "\n";

	for (int i = 0; i < people.size(); i++)
	{
		std::cout << "Who is " + people[i]->get_name() + " bestriend? ";

		std::string bestfriendName;
		std::cin >> bestfriendName;

		for (int j = 0; j < people.size(); j++)
		{
			if (i != j && bestfriendName == people[j]->get_name())
			{
				//set bestfriend
				people[i]->set_bestfriend(people[j]);
				people[j]->increment_popularity();
			}
		}


	}
	std::cout << "\n";

	for (int i = 0; i < people.size(); i++)
	{
		std::cout << people[i]->get_name() + " is bestfriends to: " + people[i]->get_bestfriend()
			+ "and has a popularity count of: " + std::to_string(people[i]->get_popularity()) + " \n";
	}
}
Person* CheckForPerson(std::vector<Person*>& people, std::string& name)
{
	Person* newPerson = nullptr;
	int age;
	if (people.size() > 0)
	{

		for (int i = 0; i < people.size(); i++)
		{
			if (name == people[i]->get_name())
			{
				newPerson = people[i];
			}
			else if (i == people.size() - 1)
			{
				//User enters age of named person
				std::cout << "Enter new persons age: ";
				std::cin >> age;
				newPerson = new Person(name, age);
				people.push_back(newPerson);
			}
		}
	}
	else
	{
		std::cout << "Enter new persons age: ";
		std::cin >> age;
		newPerson = new Person(name, age);
		people.push_back(newPerson);
	}
	return newPerson;
}
void RunPersonCarTest()
{
	int n = -1;
	std::vector<Person*> people;
	std::vector<Car*> cars;

	while (n == -1)
	{
		//User enters name
		std::string name;
		std::cout << "Enter owner name: ";
		std::cin >> name;

		/*Check if name exist.
		* If so then point to it in list
		* else create new Person and add to list
		*/
		Person* newOwner = CheckForPerson(people, name);

		std::cout << "Enter driver name: ";
		std::cin >> name;


		/*Check if name exist.
		* If so then point to it in list
		* else create new Person and add to list
		*/
		Person* newDriver = CheckForPerson(people, name);

		int model;
		std::cout << "Enter new car model #: ";

		std::cin >> model;

		Car* personsCar = new Car(model, newOwner, newDriver);
		cars.push_back(personsCar);

		std::cout << "Enter -1 to add more. \n" << "Enter anyting else to continue: ";
		std::cin >> n;
	}

	for (int i = 0; i < people.size(); i++)
	{
		people[i]->increment_age();
	}

	for (int i = 0; i < cars.size(); i++)
	{
		std::cout << std::to_string(cars[i]->get_model()) +
			" Owner: " + cars[i]->get_owner()->get_name() + " Age:" + std::to_string(cars[i]->get_owner()->get_age()) +
			" Driver: " + cars[i]->get_driver()->get_name() +
			" Age:" + std::to_string(cars[i]->get_driver()->get_age()) + "\n";
	}
}
int main()
{
	//RunBestFriendDistributor();
	RunPersonCarTest();
}

