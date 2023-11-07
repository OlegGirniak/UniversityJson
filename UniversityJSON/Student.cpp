#include "Student.h"

void Student::ShowInfo()
{
	std::cout << "- - Student - -\n";
	Person::ShowInfo();

	std::cout << "- Marks: ";
	if (!marks.empty())
	{
		auto iterator = marks.begin();
		for (size_t i = 0; i < marks.size() - 1; i++)
		{
			std::cout << *iterator << " ; ";
			++iterator;
		}
		std::cout << *iterator << ".\n" << std::endl;
	}
	else
	{
		std::cout << " empty.\n\n";
	}
}

void Student::AddMarks(unsigned mark)
{
	marks.push_back(mark);
}

UserChoice Student::Menu()
{
	std::cout << " _STUDENT_MENU_\n";

	UserChoice teacherChoices[] =
	{
		UserChoice::ShowStudentInformation,
		UserChoice::LogOut
	};

	while (true)
	{
		std::wcout << "1 - Show student info.\n2 - Log out.\n";
		std::cout << "-> Enter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice >= 1 && userChoice <= 2)
		{
			return teacherChoices[userChoice];
		}
		else
		{
			std::cout << "- Wrong choice, enter again\n";
		}
	}
}

nlohmann::json Student::to_json()
{
	nlohmann::json studentJson;
	studentJson["name"] = name;
	studentJson["password"] = password;
	studentJson["id"] = id;
	studentJson["marks"] = marks;

	return studentJson;
}

void Student::from_json(nlohmann::json& studentJson)
{
	name = studentJson["name"];
	password = studentJson["password"];
	id = studentJson["id"];
	marks = studentJson["marks"].get<std::list<int>>();
}



