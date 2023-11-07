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

void Teacher::AddGroup(Group& newGroup)
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
	std::cout << " _TEACHER_MENU_\n";

	UserChoice teacherChoices[] =
	{
		UserChoice::ShowGroupInformation,
		UserChoice::ShowStudentInformation,
		UserChoice::AddMarkForStudent,
		UserChoice::DeleteMarkForStudent,
		UserChoice::LogOut
	};

	while (true)
	{
		std::wcout << "1 - Show group info.\n2 - Show student info.\n3 - Add mark.\n4 - Delete mark.\n5 - Log out.\n"; 
		std::cout << "-> Enter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice >= 1 && userChoice <= 5)
		{
			return teacherChoices[userChoice];
		}
		else
		{
			std::cout << "- Wrong choice, enter again\n";
		}
	}
}

nlohmann::json Teacher::to_json()
{
	nlohmann::json teacherJson;

	teacherJson["name"] = name;
	teacherJson["password"] = password;
	teacherJson["id"] = id;
	for (Group& group : groups)
	{
		teacherJson["groups"].push_back(group.to_json());
	}
	return teacherJson;
}

void Teacher::from_json(nlohmann::json& teacherJson)
{
	name = teacherJson["name"];
	password = teacherJson["password"];
	id = teacherJson["id"];

	groups.clear();
	for (auto& groupJson : teacherJson["groups"])
	{
		Group group;
		group.from_json(groupJson);
		groups.push_back(group);
	}
}
