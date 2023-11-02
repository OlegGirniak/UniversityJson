#pragma once
#include "Teacher.h"
#include "Student.h"
#include <list>

class Group
{
	unsigned id;
	Teacher* teacher;
	std::list<Student> students;

public:
	Group() : teacher(nullptr), id(0) { }
	Group(Teacher* teacher, unsigned id) : teacher(teacher), id(id) { }

	void AddTeacher(Teacher* teacher);
	void AddStudent(Student& student);

	void DeleteStudent(Student& student);

	unsigned GetId() const { return id; }
	std::list<Student>& GetStudents() { return students; }
	Teacher* GetTeacher() { return teacher; }

	void ShowInfo();

	friend bool operator==(const Group& group, const Group& other)
	{
		return group.id == other.id;
	}
};


