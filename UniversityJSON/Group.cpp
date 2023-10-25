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

bool Group::AddStudent(Student student)
{
	if (students.size() == 0)
	{
		students.push_back(student);
		return true;
	}

	auto iterator = students.begin();
	for (size_t i = 0; i < students.size(); i++)
	{
		if ((*iterator).GetId() == student.GetId())
		{
			return false;
		}
	}

	students.push_back(student);
	return true;
}
