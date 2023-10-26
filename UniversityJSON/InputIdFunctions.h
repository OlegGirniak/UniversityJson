#pragma once
#include <list>
#include "Group.h"
#include "Student.h"
#include "Teacher.h"

inline std::list<Group>::iterator GetGroupById(std::list<Group>& groups)
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
		//auto iterator = groups.begin();

		for (auto it = groups.begin(); it !=  groups.end(); it++)
		{
			std::cout << (*it).GetId() << ", ";
		}

		std::cout << "-> enter group id: ";
		std::cin >> groupId;

		for (auto it = groups.begin(); it != groups.end(); it++)
		{
			if ((*it).GetId() == groupId)
			{
				return it;
			}
		}
		system("cls");
		std::cout << "-! Inncorrect group id, enter again.\n";
	}
}

inline std::list<Student>::iterator GetStudentById(std::list<Group>& groups)
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

inline std::list<Teacher>::iterator GetTeacherById(std::list<Teacher>& teachers)
{
	if (teachers.empty())
	{
		try
		{
			throw std::exception("Teachers is empty.\n");
		}
		catch (const std::exception& exc)
		{
			std::cout << exc.what();
			exit(-1);
		}
	}

	unsigned teacherId;
	while (true)
	{
		std::cout << "Teacher id: ";
		for (auto it = teachers.begin(); it != teachers.end(); it++)
		{
			std::cout << (*it).GetId() << ", ";
		}

		std::cout << "-> enter teacher id: ";
		std::cin >> teacherId;

		for (auto it = teachers.begin(); it != teachers.end(); it++)
		{
			if ((*it).GetId() == teacherId)
			{
				return it;
			}
		}
		system("cls");
		std::cout << "-! Inncorrect teachers id, enter again.\n";
	}
}

inline unsigned InputMark()
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

 inline Student InputStudent(std::list<Student>& otherStudents)
{
	std::string nameOfNewstudent = "";
	std::string passwordOfNewStudent = "";
	unsigned idOfNewStudent = -1;

	do
	{
		auto newStudent = otherStudents.begin();

		bool ifCorrectstudentDats = true;

		std::cout << "->Enter new student data:\n";

		std::cout << "1. Enter student name: ";
		std::cin >> nameOfNewstudent;
		
		std::cout << "2. Enter student password: ";
		std::cin >> passwordOfNewStudent;

		std::cout << "3. Enter student id: ";
		std::cin >> idOfNewStudent;


		for (size_t i = 0; i < otherStudents.size(); i++)
		{
			if ((*newStudent).GetPassword() == passwordOfNewStudent || (*newStudent).GetId() == idOfNewStudent)
			{
				ifCorrectstudentDats = false;
			}
			++newStudent;
		}

		if (ifCorrectstudentDats)
		{
			return Student(nameOfNewstudent, passwordOfNewStudent, idOfNewStudent);
		}
		else
		{
			system("cls");
			std::cout << "-! Inncorrect password or id, enter again.\n";
		}

	} while (true);
}

inline Teacher InputTeacher(std::list<Teacher>& otherTeachers)
{
	std::string nameOfNewTeacher = "";
	std::string passwordOfNewTeacher = "";
	unsigned idOfNewTeacher = -1;

	do
	{
		auto newTeacher = otherTeachers.begin();
		bool ifCorrectstudentDats = true;

		std::cout << "->Enter new student data:\n";

		std::cout << "1. Enter teacher name: ";
		std::cin >> nameOfNewTeacher;

		std::cout << "2. Enter teacher password: ";
		std::cin >> passwordOfNewTeacher;

		std::cout << "3. Enter teacher id: ";
		std::cin >> idOfNewTeacher;


		for (size_t i = 0; i < otherTeachers.size(); i++)
		{
			if ((*newTeacher).GetPassword() == passwordOfNewTeacher || (*newTeacher).GetId() == idOfNewTeacher)
			{
				ifCorrectstudentDats = false;
			}
			++newTeacher;
		}

		if (ifCorrectstudentDats)
		{
			return Teacher(nameOfNewTeacher, passwordOfNewTeacher, idOfNewTeacher);
		}
		else
		{
			system("cls");
			std::cout << "-! Inncorrect password or id, enter again.\n";
		}

	} while (true);
}

inline Group InputGroup(std::list<Group>& groups)
{
	unsigned newGroupId = -1;

	auto currentGroup = groups.begin();
	while (true)
	{
		bool ifCorrectGroup = true;

		std::cout << "Enter id of new group: ";
		std::cin >> newGroupId;

		for (size_t i = 0; i < groups.size(); i++)
		{
			if ((*currentGroup).GetId() == newGroupId)
			{
				ifCorrectGroup = false;
			}
		}

		if (!ifCorrectGroup)
		{
			system("cls");
			std::cout << "-! inncorrect id, enter again.\n";
		}
		else
		{
			break;
		}
	}

	return Group(nullptr, newGroupId);
}
