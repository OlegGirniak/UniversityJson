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
	std::cout << " __TEACHER__MENU__\n";

	std::cout << "1 - Show information.\n2 - Exit\n";

	while (true)
	{
		std::cout << "-> Enter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice == 1)
		{
			return UserChoice::ShowStudentInformationById;
		}
		else if (userChoice == 2)
		{
			return UserChoice::Exit;
		}
		else
		{
			std::cout << "-! Wrong choice, enter again\n";
		}
	}
}
