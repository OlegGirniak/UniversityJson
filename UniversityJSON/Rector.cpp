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

void Rector::AddGroupForTeacher(std::list<Teacher>& teachers, std::list<Group>& groups)
{
	if (teachers.empty() || groups.empty())
	{
		std::cout << "-! Teachers or groups is empty.\n ";
	}
	else
	{
		std::cout << "\t-> Chooce teacher: \n";
		auto teacher = GetTeacherById(teachers);
		

		while (true)
		{
			bool ifGroupExists = false;

			std::cout << "\t-> Chooce group: \n";

			auto group = GetGroupById(groups);

			for (auto teacherGroup = (*teacher).GetGroups().begin(); teacherGroup != (*teacher).GetGroups().end(); teacherGroup++)
			{
				if ((*group).GetId() == (*teacherGroup).GetId())
				{
					ifGroupExists = true;
					break;
				}
			}

			if (ifGroupExists)
			{
				std::cout << "\t-! Group exists, enter again, if press 1 to exit or 2 to continue.\n";
				int ifExit;
				std::cin >> ifExit;
				if (ifExit == 1)
					return;
			}
			else
			{
				(*teacher).AddGroup(*group);
				std::cout << "\t + Group is added.\n";
				return;
			}
		}
	}
}

void Rector::AddStudentInGroup(std::list<Group>& groups)
{
	std::cout << "\tADD STUDENT IN GROUP\n";

	std::cout << "\tChoose group by id: \n";

	auto group = GetGroupById(groups);

	auto student = InputStudent(groups);

	(*group).AddStudent(student);
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

void Rector::AddMarkForStudent(std::list<Group>& groups)
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

void Rector::DeleteGroup(std::list<Group>& groups)
{
	std::cout << "\tDELETE GROUP\n";

	if(groups.empty())
	{
		std::cout << "\t-! University is empty.\n";
		
	}
	else
	{
		std::cout << "\tChoose Group by id:\n";
		auto deleteGroup = GetGroupById(groups);

		groups.remove(*deleteGroup);

		std::cout << "\t + Group is deleted.\n";
	}
}

void Rector::DeleteTeacher(std::list<Teacher>& teachers, std::list<Group>& groups)
{
	std::cout << "\tDELETE TEACHER\n";

	if (teachers.empty())
	{
		std::cout << "\t-! Teachers is empty.\n";
		return;
	}
	else
	{
		std::cout << "\tChoose teacher by id:\n";

		auto teacher = GetTeacherById(teachers);

		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			if ((*group).GetTeacher()->GetId() == (*teacher).GetId())
			{
				(*group).AddTeacher(nullptr);

				std::cout << "\t ! Group (Id: " << (*group).GetId() << ") has lost teacher.\n";
				break;
			}
		}

		teachers.remove(*teacher);

		std::cout << "\t + Teacher is deleted\n";
	}
}

void Rector::DeleteStudent(std::list<Group>& groups)
{
	std::cout << "\tDELETE STUDENT\n";

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
			auto deleteStudent = GetStudentById((*group).GetStudents());

			(*group).GetStudents().remove(*deleteStudent);

			std::cout << "\t + Student is deleted\n";
		}
	}
}

void Rector::DeleteMarkFodStudent(std::list<Group>& groups)
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
