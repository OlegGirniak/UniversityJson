#include "Group.h"

bool Group::AddTeacher(Teacher* teacher)
{
	if (this->teacher != nullptr && this->teacher != teacher)
	{
		this->teacher = teacher;
		return true;
	}
	return false;
}

void Group::AddStudent(Student& student)
{
	students.push_back(student);
}

void Group::ShowInfo()
{
	std::cout << "- - Group id: " << id << std::endl;

	if (teacher != nullptr)
	{
		teacher->ShowInfo();
	}

	auto currentStudent = students.begin();
	if (!students.empty())
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			(*currentStudent).ShowInfo();
		}
	}
}
