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
	void AddTeacherInUniversity(std::list<Teacher>& teachers);
	void AddTeacherForGroup(std::list<Group>& groups, std::list<Teacher>& teachers);
	void AddGroupForTeacher(std::list<Teacher>& teachers, std::list<Group>& groups);
	void AddStudentInGroup(std::list<Group>& groups);
	void AddMarkForStudent(std::list<Group>& groups);

	//delete methods
	void DeleteGroup(std::list<Group>& groups);
	void DeleteTeacher(std::list<Teacher>& teachers, std::list<Group>& groups);
	void DeleteStudent(std::list<Group>& groups);
	void DeleteMarkFodStudent(std::list<Group>& groups);

	//show methods
	void ShowAllInformation(std::list<Group>& groups, std::list<Teacher>& teachers);
	void ShowGroupInformationById(std::list<Group>& groups);
	void ShowStudentInformationById(std::list<Group>& groups);
	void ShowTeacherInformationById(std::list<Teacher>& teachers);

	void Menu() {}

};

