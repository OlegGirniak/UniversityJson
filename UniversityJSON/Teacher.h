#pragma once
#include "Person.h"
#include <list>

class Group;

class Teacher : public Person
{
	std::list<int> groups;

public: 
	Teacher() : Person() { }
	Teacher(std::string name, std::string password, unsigned id) : Person(name, password, id) { }

	std::list<int> GetGroups() const { return groups; }

	void AddMarkForStudent(std::list<Group>& group);

	void ShowInfo();
};

