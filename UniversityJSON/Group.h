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

	bool AddTeacher(Teacher* teacher);
	void AddStudent(Student& student);

	unsigned GetId() const { return id; }
	std::list<Student>& GetStudents() { return students; }
	Teacher* GetTeacher() { return teacher; }

	void ShowInfo();

};

