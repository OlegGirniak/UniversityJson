#pragma once
#include "Person.h"
#include <list>


class Student : public Person
{
	std::list<int> marks;

public:
	Student() : Person() { }
	Student(std::string name, std::string password, unsigned id) : Person(name, password, id) { }

	std::list<int> GetMarks() const { return marks; }
	
	void ShowInfo();
	bool AddMarks(unsigned mark);
};

