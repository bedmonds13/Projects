#pragma once
#include "Person.h"
class Car
{
	int model;
	Person* owner;
	Person* driver;
public:
	Car() :model{ 0 }, owner{ nullptr }, driver{ nullptr }{}
	Car(int modelNumber) :model{ modelNumber }, owner{ nullptr }, driver{ nullptr }{}
	Car(int modelNumber, Person* newOwner) :model{ modelNumber }, owner{ newOwner }, driver{ nullptr }{}
	Car(int modelNumber, Person* newOwner, Person* newDriver) :model{ modelNumber }, owner{ newOwner }, driver{ newDriver }{}

	Person* get_owner();
	Person* get_driver();
	int get_model();

};

