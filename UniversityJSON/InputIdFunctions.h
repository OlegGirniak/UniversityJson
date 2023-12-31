#pragma once
#include <list>
#include "Group.h"
#include "Student.h"
#include "Teacher.h"

inline std::list<Group>::iterator GetGroupById(std::list<Group>& groups)
{
	if (groups.empty())
	{
		std::cout << "\t -! Univerasity is emty.\n";

	}
	else
	{
		std::cout << "\t - - Choose group by ID - -\n";
		unsigned groupId;
		while (true)
		{
			std::cout << "\t-> Groups id: ";

			for (auto it = groups.begin(); it != groups.end(); it++)
			{
				std::cout << (*it).GetId() << ", ";
			}
			std::cout << std::endl;

			std::cout << "\n\t-> Enter group id: ";
			std::cin >> groupId;

			for (auto it = groups.begin(); it != groups.end(); it++)
			{
				if ((*it).GetId() == groupId)
				{
					return it;
				}
			}
			system("cls");
			std::cout << "\t-! Inncorrect group id, enter again.\n";
		}
	}
}

inline std::list<Student>::iterator GetStudentById(std::list<Student>& students)
{
	unsigned studentId;
	while (true)
	{
		std::cout << "\t<- Students id: ";
		for (auto student = students.begin(); student != students.end(); student++)
		{
			std::cout << (*student).GetId() << "   ";
		}
		std::cout << std::endl;

		std::cout << "\t-> Enter student id: ";
		std::cin >> studentId;

		for (auto student = students.begin(); student != students.end(); student++)
		{
			if ((*student).GetId() == studentId)
			{
				return student;
			}
		}

		std::cout << "\t-! Inncorret student id, enter again.\n";
	}
}

inline std::list<Teacher>::iterator GetTeacherById(std::list<Teacher>& teachers)
{
	if (teachers.empty())
	{
		try
		{
			throw std::exception("\n-! Teachers is empty.\n");
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
		std::cout << "\t->Teacher id: ";
		for (auto it = teachers.begin(); it != teachers.end(); it++)
		{
			std::cout << (*it).GetId() << ", ";
		}

		std::cout << "\t-> Enter teacher id: ";
		std::cin >> teacherId;

		for (auto it = teachers.begin(); it != teachers.end(); it++)
		{
			if ((*it).GetId() == teacherId)
			{
				return it;
			}
		}
		system("cls");
		std::cout << "\t-! Inncorrect teachers id, enter again.\n";
	}
}

inline unsigned InputMark()
{
	unsigned mark;
	while (true)
	{
		std::cout << "\t-> Enter mark: ";
		std::cin >> mark;

		if (mark > 0 && mark < 13)
		{
			return mark;
		}
		else
		{
			system("cls");
			std::cout << "\t-! Inncorrect mark, enter again.\n";
		}
	}
}

inline Student InputStudent(std::list<Group>& groups)
{
	std::string newStudentPassword = "";
	std::string newStudentName = "";
	unsigned idNewStudentId = -1;

	while (true)
	{

		std::cout << "\t-> Enter new student data:\n";
		std::cout << "\t-> Enter new student name: ";

		std::cin >> newStudentName;

		while (true)
		{
			bool ifPasswordIsreserved = false;

			std::cout << "\t-> Enter new student password: ";
			std::cin >> newStudentPassword;

			for (auto group = groups.begin(); group != groups.end(); group++)
			{
				for (auto student = (*group).GetStudents().begin(); student != (*group).GetStudents().end(); student++)
				{
					if ((*student).GetPassword() == newStudentPassword)
					{
						ifPasswordIsreserved = true;
						break;
					}
				}
			}

			if (ifPasswordIsreserved)
			{
				std::cout << "-! Password is reserved enter again.\n";
			}
			else
			{
				while (true)
				{
					bool ifIdIsreserved = false;

					std::cout << "\t-> Enter new student id: ";
					std::cin  >> idNewStudentId;


					for (auto group = groups.begin(); group != groups.end(); group++)
					{
						for (auto student = (*group).GetStudents().begin(); student != (*group).GetStudents().end(); student++)
						{
							if ((*student).GetId() == idNewStudentId)
							{
								ifIdIsreserved = true;
							}
						}
					}

					if (ifIdIsreserved)
					{
						std::cout << "-! Id is reserved enter again.\n";
					}
					else
					{
						return Student(newStudentName, newStudentPassword, idNewStudentId);
					}
				}
			}
		}
	}
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

		std::cout << "\t->Enter new teacher data:\n";

		std::cout << "\t1. Enter teacher name: ";
		std::cin >> nameOfNewTeacher;

		std::cout << "\t2. Enter teacher password: ";
		std::cin >> passwordOfNewTeacher;

		std::cout << "\t3. Enter teacher id: ";
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
			std::cout << "\t-! Inncorrect password or id, enter again.\n";
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

		std::cout << "\t->Enter id of new group: ";
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
			std::cout << "\t-! inncorrect id, enter again.\n";
		}
		else
		{
			break;
		}
	}

	return Group(nullptr, newGroupId);
}
