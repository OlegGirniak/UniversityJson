#pragma once
#include "Teacher.h"
#include "Student.h"
#include "nlohmann/json.hpp"
#include <list>

class Group
{
	unsigned id;
	std::list<Student> students;

public:
	Group() : id(0) { }
	Group(Teacher* teacher, unsigned id) : id(id) { }

	void AddStudent(Student& student);

	void DeleteStudent(Student& student);

	unsigned GetId() const { return id; }
	std::list<Student>& GetStudents() { return students; }

	void ShowInfo();

	friend bool operator==(const Group& group, const Group& other)
	{
		return group.id == other.id;
	}

	void to_json(nlohmann::json& j);
	void from_json(nlohmann::json& j, int indexOfGroup);
};


