#include "Teacher.h"
#include "InputIdFunctions.h"

void Teacher::AddMarkForStudent()
{
	std::cout << "\tADD MARK FOR STUDENT\n ";

	if (groups.empty())
	{
		std::cout << "-! Groups is empty\n";
		return;
	}

	std::cout << "\nChoose group by id: \n";
	auto group = GetGroupById(groups);

	auto student = GetStudentById((*group).GetStudents());

	auto mark = InputMark();

	(*student).AddMarks(mark);

	std::cout << "\t + Mark is added.\n";
}

void Teacher::AddStudentInUniversity()
{
	std::cout << "\tADD STUDENT IN GROUP\n";

	std::cout << "\tChoose group by id: \n";

	auto group = GetGroupById(groups);

	auto student = InputStudent(groups);

	(*group).AddStudent(student);
}

void Teacher::AddGroup(Group newGroup)
{
	groups.push_back(newGroup);
}

void Teacher::ShowInfo()
{
	std::cout << "- - Teacher - -\n";
	Person::ShowInfo();

	if (!groups.empty())
	{
		std::cout << "\tGroup id: ";

		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			std::cout << (*group).GetId() << "  ";
		}
		std::cout << std::endl;
	}
}
