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


	//add methods
	void AddGroup(std::list<Group>& groups);
	void AddTeacherForGroup(std::list<Group>& groups, std::list<Teacher>& teachers);
	void AddTeacherInUniversity(std::list<Teacher>& teachers);
	void AddGroupForTeacher(std::list<Teacher>& teachers, std::list<Group>& groups);
	void AddStudentInGroup(std::list<Group>& groups);
	void AddMarkForStudent(std::list<Group>& groups);

	//delete methods


	//show methods
	void ShowAllInformation(std::list<Teacher>& teachers, std::list<Group>& groups);
	void ShowAllInformation(std::list<Group>& groups, std::list<Teacher>& teachers);
	void ShowGroupInformationById(std::list<Group>& groups);
	void ShowStudentInformationById(std::list<Group>& groups);
	void ShowTeacherInformationById(std::list<Teacher>& teachers);

};

