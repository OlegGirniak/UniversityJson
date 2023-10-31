#pragma once
#include "Rector.h"
#include "Teacher.h"
#include "Group.h"
#include "Student.h"
#include<list>

class University
{
	Rector rector;
	std::list<Teacher> teachers;
	std::list<Group> groups;

public:

	Rector& GetRector() { return rector; }
	std::list<Group>& GetGroups() { return groups; }
	std::list<Teacher>& GetTeachers() { return teachers; }
	
};

