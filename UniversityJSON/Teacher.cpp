#include "Teacher.h"
#include "InputIdFunctions.h"

void Teacher::AddMarkForStudent(std::list<Group>& groups)
{
	auto student = GetStudentById(groups);

	unsigned mark = InputMark();

	(*student).AddMarks(mark);
}

void Teacher::AddStudent()
{
	auto group = GetGroupById(groups);

	Student	newStudent = InputStudent((*group).GetStudents());

	(*group).AddStudent(newStudent);
}

void Teacher::ShowInfo()
{
	std::cout << "- Teacher -\n Name: " << name << "\nPassword: " << password << "\nId: " << id << std::endl;
}
