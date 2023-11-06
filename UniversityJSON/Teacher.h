#pragma once
#include "Person.h"
#include "nlohmann/json.hpp"
#include <list>

class Group;

class Teacher : public Person
{
	std::list<Group> groups;

public: 
	Teacher() : Person() { }
	Teacher(std::string name, std::string password, unsigned id) : Person(name, password, id) { }

	std::list<Group>& GetGroups() { return groups; }

	void AddMarkForStudent();
	void AddGroup(Group newGroup);

	void ShowStudentInformation();
	void ShowGroupInformation();
	void DeleteMarkForStudent();

	void ShowInfo();

	UserChoice Menu();

	friend bool operator==(const Teacher& teacher, const Teacher& other)
	{
		return teacher.id == other.id;
	}

	nlohmann::json to_json();
	void from_json(nlohmann::json& teacherJson);
};

