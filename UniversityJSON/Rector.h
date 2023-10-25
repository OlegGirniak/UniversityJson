#pragma once
#include "Person.h"
#include <list>

class Student;
class Teacher;
class Group;

class Rector : public Person
{
public:
	Rector() : Person("rector", "rector", 1) { }

	void AddGroup(std::list<Group>& groups);
	void AddTeacherForgroup(std::list<Group>& groups);
	void GroupForTeacher(std::list<Teacher>& teachers);
	void AddStudentInGroup(std::list<Group>& groups);
	void ShowAllInformation(std::list<Teacher>& teachers, std::list<Group>& groups);
};

