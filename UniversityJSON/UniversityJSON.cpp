#include <iostream>
#include "University.h"

int main()
{
	University university;

	auto rector = university.GetRector();
	std::list<Group>& groups = university.GetGroups();
	std::list<Teacher>& teachers = university.GetTeachers();

	

}

