#include <iostream>
#include "University.h"
#include "Profession.h"	

std::pair<Profession, unsigned> LogIn(Rector& rector, std::list<Teacher>& teachers, std::list<Group>& froups);

int main()
{
	University university;

	std::pair<Profession, unsigned> userData = LogIn(university.GetRector(), university.GetTeachers(), university.GetGroups());

	switch (userData.first)
	{
	case Profession::Rector:
	{
		Rector user = university.GetRector();
	}
	case Profession::Teacher:
	{
		Teacher& user = *(university.GetTeachers().begin());

		for (auto teacher = university.GetTeachers().begin(); teacher != university.GetTeachers().end(); teacher++)
		{
			if (userData.second == (*teacher).GetId())
			{
				user = *teacher;
				break;
			}
		}
	}
	case Profession::Student:
	{

	}
	default:
		break;
	}
}



std::pair<Profession, unsigned> LogIn(Rector& rector, std::list<Teacher>& teachers, std::list<Group>& groups) 
{

	while (true)
	{
		std::cout << "\t-> Enter password: ";
		std::string inputPassword;

		if (inputPassword == rector.GetPassword())
		{
			return std::pair<Profession, unsigned>(Profession::Rector, rector.GetId());
		}
		
		for (auto teacher = teachers.begin(); teacher != teachers.end(); teacher++)
		{
			if (inputPassword == (*teacher).GetPassword())
			{
				return std::pair<Profession, unsigned>(Profession::Teacher, (*teacher).GetId());
			}
		}

		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			for (auto student = (*group).GetStudents().begin(); student != (*group).GetStudents().end(); student++)
			{
				if (inputPassword == (*student).GetPassword())
				{
					return std::pair<Profession, unsigned>(Profession::Student, (*student).GetId());
				}
			}
		}

		std::cout << "\t -! Inncorrect password, enter again\n";
	}
}