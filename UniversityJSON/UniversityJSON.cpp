#include <iostream>
#include "University.h"

int main()
{
	University university;

	auto rector = university.GetRector();

	rector.AddGroup(university.GetGroups());

	rector.AddTeacherInUniversity(university.GetTeachers());

	std::cout << "Groups: " << university.GetGroups().size() << std::endl;
	std::cout << "Teachers: " << university.GetTeachers().size() << std::endl;
	

	rector.AddTeacherForGroup(university.GetGroups(), university.GetTeachers());
	
}

