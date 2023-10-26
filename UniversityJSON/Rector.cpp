#include "Rector.h"
#include "InputIdFunctions.h"

void Rector::AddGroup(std::list<Group>& groups)
{
	Group newGroup = InputGroup(groups);

	groups.push_back(newGroup);

	std::cout << "Group is added!\n";
}

void Rector::AddTeacherForGroup(std::list<Group>& groups, std::list<Teacher>& teachers)
{
	auto group = GetGroupById(groups);
	auto teacher = GetTeacherById(teachers);

	if ((*group).GetTeacher() == nullptr)
	{
		(*group).AddTeacher(&(*teacher));
		std::cout << "teachers is added for group\n";
	}
	else
	{
		std::cout << "teacher is reserved\n";
	}
}

void Rector::AddTeacherInUniversity(std::list<Teacher>& teachers)
{
	auto teacher = InputTeacher(teachers);

	teachers.push_back(teacher);

	std::cout << "Teacher is added.\n";
}

