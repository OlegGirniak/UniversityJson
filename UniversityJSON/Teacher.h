#pragma once
#include "Person.h"
#include <list>

class Group;

class Teacher : public Person
{
	std::list<Group> groups;

public: 
	Teacher() : Person() { }
	Teacher(std::string name, std::string password, unsigned id) : Person(name, password, id) { }

	std::list<Group>& GetGroups() { return groups; }

	void AddMarkForStudent(std::list<Group>& group);
	void AddStudent();

	void ShowInfo();
};

