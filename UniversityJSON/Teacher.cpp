#include "Teacher.h"
#include "InputIdFunctions.h"

void Teacher::AddMarkForStudent(std::list<Group>& groups)
{
	auto group = GetGroupById(groups);

	auto student = GetStudentById((*group).GetStudents());

	unsigned newMark = InputMark();

	(*student).AddMarks(newMark);

	std::cout << "\t + Mark is added.\n";
}

void Teacher::AddStudent()
{
	auto group = GetGroupById(groups);

	Student	newStudent = InputStudent((*group).GetStudents());

	(*group).AddStudent(newStudent);
}

void Teacher::ShowInfo()
{
	std::cout << "- - Teacher - -\n";
	Person::ShowInfo();
}
