#pragma once
#include <list>
#include "Group.h"
#include "Student.h"
#include "Teacher.h"

std::list<Group>::iterator GetGroupById(std::list<Group>& groups)
{
	if (groups.empty())
	{
		try
		{
			throw std::exception("University is empty.\n");
		}
		catch (const std::exception& exc)
		{
			std::cout << exc.what();
			exit(-1);
		}
	}

	unsigned groupId;
	while (true)
	{
		std::cout << "Groups id: ";
		auto iterator = groups.begin();
		for (size_t i = 0; i < groups.size(); i++)
		{
			std::cout << (*iterator).GetId() << ", ";
			++iterator;
		}
		std::cout << (*iterator).GetId() << ".\n";
		iterator = groups.begin();

		std::cout << "-> enter group id: ";
		std::cin >> groupId;

		for (size_t i = 0; i < groups.size(); i++)
		{
			if ((*iterator).GetId() == groupId)
			{
				return iterator;
			}
		}
		system("cls");
		std::cout << "-! Inncorrect group id, enter again.\n";
	}
}

std::list<Student>::iterator GetStudentById(std::list<Group>& groups)
{
	auto group = GetGroupById(groups);
	std::list<Student>& students = (*group).GetStudents();

	if (students.empty())
	{
		try
		{
			throw std::exception("Group is empty.\n");
		}
		catch (const std::exception& exc)
		{
			std::cout << exc.what();
			exit(-1);
		}
	}

	unsigned studentId;
	while (true)
	{
		std::cout << "-Student id: ";
		auto iterator = students.begin();
		for (size_t i = 0; i < students.size() - 1; i++)
		{
			std::cout << (*iterator).GetId() << ", ";
			++iterator;
		}
		std::cout << (*iterator).GetId() << "\n";

		std::cout << "-> enter student id: ";
		std::cin >> studentId;

		for (size_t i = 0; i < groups.size(); i++)
		{
			if ((*iterator).GetId() == studentId)
			{
				return iterator;
			}
		}
		system("cls");
		std::cout << "-! Inncorrect student id, enter again.\n";
	}
}

unsigned InputMark()
{
	unsigned mark;
	while (true)
	{
		std::cout << "-> enter mark: ";
		std::cin >> mark;

		if (mark > 0 && mark < 13)
		{
			return mark;
		}
		else
		{
			system("cls");
			std::cout << "-! Inncorrect mark, enter again.\n";
		}
	}
}