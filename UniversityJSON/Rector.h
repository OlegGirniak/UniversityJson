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
	void AddTeacherForGroup(std::list<Group>& groups, std::list<Teacher>& teachers);
	void AddTeacherInUniversity(std::list<Teacher>& teachers);
	void GroupForTeacher(std::list<Teacher>& teachers);
	void AddStudentInGroup(std::list<Group>& groups);
	void ShowAllInformation(std::list<Teacher>& teachers, std::list<Group>& groups);
};

