#include <iostream>
#include "University.h"

int main()
{
	University university;

	auto rector = university.GetRector();
	std::list<Group>& groups = university.GetGroups();
	std::list<Teacher>& teachers = university.GetTeachers();

	rector.AddGroup(groups);

	rector.AddTeacherInUniversity(teachers);

	rector.AddTeacherForGroup(groups, teachers);

	rector.DeleteTeacher(teachers, groups);

	rector.ShowGroupInformationById(groups);
}

