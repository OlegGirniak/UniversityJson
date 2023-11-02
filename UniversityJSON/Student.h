#pragma once
#include "Person.h"
#include <list>


class Student : public Person
{
	std::list<int> marks;

public:
	Student() : Person() { }
	Student(std::string name, std::string password, unsigned id) : Person(name, password, id) { }

	std::list<int>& GetMarks() { return marks; }
	
	void ShowInfo();
	void AddMarks(unsigned mark);

	UserChoice Menu();

	friend bool operator==(const Student& other1, const Student& other2)
	{
		return other1.id == other2.id;
	}
};

