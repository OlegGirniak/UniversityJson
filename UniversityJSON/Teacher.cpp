#include "Teacher.h"
#include "InputIdFunctions.h"

void Teacher::AddMarkForStudent(std::list<Group>& groups)
{
	auto student = GetStudentById(groups);

	unsigned mark = InputMark();

	(*student).AddMarks(mark);
}

void Teacher::ShowInfo()
{
	std::cout << "- - Teacher - -\n";
	Person::ShowInfo();
	std::cout << "Groups: ";

	if (groups.size() > 0)
	{
		auto iterator = groups.begin();
		for (size_t i = 0; i < groups.size() - 1; i++)
		{
			std::cout << *iterator << ", ";
			++iterator;
		}
		std::cout << *iterator << ".\n" << std::endl;
	}
	else
	{
		std::cout << " empty\n\n";
	}
}
