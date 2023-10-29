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
