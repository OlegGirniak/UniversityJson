#include "Teacher.h"
#include "InputIdFunctions.h"

void Teacher::AddMarkForStudent()
{
	std::cout << "\tADD MARK FOR STUDENT\n ";

	if (groups.empty())
	{
		std::cout << "-! Groups is empty\n";
		return;
	}

	std::cout << "\nChoose group by id: \n";
	auto group = GetGroupById(groups);

	auto student = GetStudentById((*group).GetStudents());

	auto mark = InputMark();

	(*student).AddMarks(mark);

	std::cout << "\t + Mark is added.\n";
}

void Teacher::AddGroup(Group newGroup)
{
	groups.push_back(newGroup);
}

void Teacher::ShowStudentInformation()
{
	std::cout << "_SHOW_STUDENT_INFORMATION_\n";

	if (groups.empty())
	{
		std::cout << "Groups is empty.\n";
	}
	else
	{
		auto group = GetGroupById(groups);

		if ((*group).GetStudents().empty())
		{
			std::cout << "Students are empty.\n";
		}
		else
		{
			auto student = GetStudentById((*group).GetStudents());

			(*student).ShowInfo();
		}
	}
}

void Teacher::ShowGroupInformation()
{
	std::cout << "_SHOW_GROUP_INFORMATION_\n";

	if (groups.empty())
	{
		std::cout << "Groups is empty.\n";
	}
	else
	{
		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			(*group).ShowInfo();
		}
	}
}

void Teacher::DeleteMarkForStudent()
{
	std::cout << "\tDELETE MARK  FOR STUDENT\n";

	if (groups.empty())
	{
		std::cout << "\tUniversity is empty.\n";
	}
	else
	{
		auto group = GetGroupById(groups);

		if ((*group).GetStudents().empty())
		{
			std::cout << "\t -! Group is empty";
		}
		else
		{
			auto student = GetStudentById((*group).GetStudents());

			if ((*student).GetMarks().empty())
			{
				std::cout << "\t -! Students has not marks\n";
			}
			else
			{
				auto deleteMark = InputMark();

				(*student).GetMarks().remove(deleteMark);

				std::cout << "\t + Mark is deleted\n";
			}
		}
	}
}

void Teacher::ShowInfo()
{
	std::cout << "- - Teacher - -\n";
	Person::ShowInfo();

	if (!groups.empty())
	{
		std::cout << "\tGroup id: ";

		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			std::cout << (*group).GetId() << "  ";
		}
		std::cout << std::endl;
	}
}

UserChoice Teacher::Menu()
{
	std::cout << " __TEACHER__MENU__\n";

	std::cout << "1 - Show group information.\n2 - Show group information\n3 - Show student information\n4 - Delete mark.\n5 - Exit\n";

	while (true)
	{
		std::cout << "-> Enter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice == 1)
		{
			return UserChoice::ShowGroupInformationById;
		}
		else if (userChoice == 2) 
		{
			return UserChoice::ShowGroupInformationById;
		}
		else if (userChoice == 3)
		{
			return UserChoice::ShowStudentInformationById;
		}
		else if (userChoice == 4)
		{
			return UserChoice::DeleteMarkForStudent;
		}
		else if (userChoice == 5)
		{
			return UserChoice::Exit;
		}
		else
		{
			std::cout << "-! Wrong choice, enter again\n";
		}
	}
}
