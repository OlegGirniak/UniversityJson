#include "Group.h"

void Group::AddTeacher(Teacher* teacher)
{
	this->teacher = teacher;
}

void Group::AddStudent(Student& student)
{
	students.push_back(student);
}

void Group::ShowInfo()
{
	std::cout << " - - Group - -\n Id: " << id << std::endl;

	if (teacher != nullptr)
	{
		std::cout << "__Head Teacher__\n";
		teacher->ShowInfo();
	}
	else
	{
		std::cout << " - - Head Teacher Empty - - \n";
	}

	if (!students.empty())
	{
		for (auto it = students.begin(); it != students.end(); it++)
		{
			(*it).ShowInfo();
		}
	}
	else
	{
		std::cout << " - - Students Empty - - \n";
	}
}
