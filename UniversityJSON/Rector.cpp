#include "Rector.h"
#include "InputIdFunctions.h"

void Rector::AddGroup(std::list<Group>& groups)
{
	unsigned idOfNewGroup= -1;

	if (groups.empty())
	{
		std::cout << "\t -> Enter new group data:\n";
		std::cout << "\t Enter id: ";
		std::cin >> idOfNewGroup;

		groups.push_back(Group(nullptr, idOfNewGroup));
		std::cout << "\t + Group is added.\n";
	}
	else
	{
		while (true)
		{
			bool ifIdIsreserved = false;
			std::cout << "\t -> Enter new group data:\n";
			std::cout << "\t Enter id: ";
			std::cin >> idOfNewGroup;

			for (auto group = groups.begin(); group != groups.end(); group++)
			{
				if ((*group).GetId() == idOfNewGroup)
				{
					ifIdIsreserved = true;
					break;
				}
			}

			if (ifIdIsreserved)
			{
				std::cout << "\t-! Id is reserved, enter again.\n";
			}
			else
			{
				groups.push_back(Group(nullptr, idOfNewGroup));
				std::cout << "\t + Group is added.\n";
				return;
			}
		}
	}
}

void Rector::AddTeacherForGroup(std::list<Group>& groups, std::list<Teacher>& teachers)
{
	std::cout << "Add teacher for group.\n";

	auto group = GetGroupById(groups);

	if ((*group).GetTeacher() == nullptr )
	{
		auto teacher = GetTeacherById(teachers);

		(*group).AddTeacher(&(*teacher));
	}
	else
	{
		std::cout << "Teacher is reserved in this group\n";
	}

}

void Rector::AddTeacherInUniversity(std::list<Teacher>& teachers)
{
	
	unsigned idOfNewTeacher = -1;

	if (teachers.empty())
	{
		std::cout << "-> Enter new teacher data.\n";
		std::cout << "\tEnter new teacher name: ";
		std::string nameOfNewTeacher;
		std::cin >> nameOfNewTeacher;

		std::cout << "\tEnter new teacher password: ";
		std::string passwordOfNewTeacher;
		std::cin >> passwordOfNewTeacher;
		
		std::cout << "\tEnter new teacher id: ";
		std::cin >> idOfNewTeacher;

		teachers.push_back(Teacher(nameOfNewTeacher, passwordOfNewTeacher, idOfNewTeacher));
	}
	else
	{
		while (true)
		{
			bool ifIdIsReserved = false;
			
			std::cout << "-> Enter new teacher data.\n";
			std::cout << "\tEnter new teacher name: ";
			std::string nameOfNewTeacher;
			std::cin >> nameOfNewTeacher;

			std::cout << "\tEnter new teacher password: ";
			std::string passwordOfNewTeacher;
			std::cin >> passwordOfNewTeacher;

			std::cout << "\tEnter new teacher id: ";
			std::cin >> idOfNewTeacher;

			for (auto teacher = teachers.begin(); teacher != teachers.end(); teacher++)
			{
				if ((*teacher).GetId() == idOfNewTeacher)
				{
					ifIdIsReserved = true;
				}
			}

			if (ifIdIsReserved)
			{
				std::cout << "\n-! Id is reserved, enter again.\n";
			}
			else
			{
				teachers.push_back(Teacher(nameOfNewTeacher, passwordOfNewTeacher, idOfNewTeacher));
				return;
			}
		}
	}
	
}

void Rector::ShowAllInformation(std::list<Group>& groups, std::list<Teacher>& teachers)
{
	std::cout << " - - - Rector - - -\n";
	Person::ShowInfo();

	if (!teachers.empty())
	{
		for (auto teacher = teachers.begin(); teacher != teachers.end(); teacher++)
		{
			(*teacher).ShowInfo();
		}
	}
	else
	{
		std::cout << "Teachers is empty.\n";
	}

	if (!groups.empty())
	{
		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			(*group).ShowInfo();
		}
	}
	else
	{
		std::cout << "Group is empty.\n";
	}
}

void Rector::ShowGroupInformationById(std::list<Group>& groups)
{
	if (!groups.empty())
	{
		auto group = GetGroupById(groups);
		(*group).ShowInfo();
	}
	else
	{
		std::cout << " - - Groups is empty - -\n";
	}
}

void Rector::ShowStudentInformationById(std::list<Group>& groups)
{
	if (!groups.empty())
	{
		auto group = GetGroupById(groups);

		if (!((*group).GetStudents().empty()))
		{
			auto students = (*group).GetStudents();

			auto student = GetStudentById(students);

			(*student).ShowInfo();
		}
		else
		{
			std::cout << "\t -! This group is empty.\n";
		}
	}
	else
	{
		std::cout << "\t-! Groups is empty,\n";
	}
}

void Rector::ShowTeacherInformationById(std::list<Teacher>& teachers)
{
	if (!teachers.empty())
	{
		auto teacher = GetTeacherById(teachers);

		(*teacher).ShowInfo();
	}
	else
	{
		std::cout << "\t-! Teachers is empty.\n";
	}
}
