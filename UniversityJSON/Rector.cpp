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
		std::cout << " - Teachers or groups is empty.\n ";
	}
	else
	{
		std::cout << "-> Chooce teacher: \n";
		auto teacher = GetTeacherById(teachers);
		

		while (true)
		{
			bool ifGroupExists = false;

			std::cout << "-> Chooce group: \n";

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
				std::cout << "- Group exists, enter again, if press 1 to exit or 2 to continue.\n";
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

void Rector::DeleteMarkForStudent(std::list<Group>& groups)
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

void Rector::ChangePassword()
{
	std::cout << "_CHANGE_PASSWORD_\n";
	
	while (true)
	{
		std::cout << "->Enter old password: ";
		std::string tmpPassword;
		std::cin >> tmpPassword;

		if (tmpPassword == password)
		{
			tmpPassword.clear();
			std::cout << "->Enter new password: ";
			std::cin >> tmpPassword;
			password = tmpPassword;
			std::cout << " + Password is changed.\n";
			return;
		}
		else
		{
			std::cout << " - Wrong password, enter again.\n";
		}
	}
}

void Rector::ChangeName()
{
	std::cout << "_CHANGE_NAME_\n";

	while (true)
	{
		std::cout << "->Enter password: ";
		std::string tmpPassword;
		std::cin >> tmpPassword;

		if (tmpPassword == password)
		{
			tmpPassword.clear();
			std::cout << "->Enter new name: ";
			std::string newName;
			std::cin >> newName;
			name = newName;
			std::cout << " + Name is changed.\n";
			return;
		}
		else
		{
			std::cout << " - Wrong password, enter again.\n";
		}
	}
}

UserChoice Rector::Menu()
{
	std::cout << " _RECTOR_MENU_\n";

	std::cout << " - ADDING - \n1 - Add group.\n2 - Add teacher.\n3 - Add student.\n4 - Add mark.\n5 - Add group for teacher.\n";
	std::cout << "6 - Show university info.\n7 - Show group info.\n8 - Show student info.\n9 - Show teacher info.\n";
	std::cout << "10 - Delete group.\n11 - Delete teacher.\n12 - Delete student.\n13 - Delete mark.\n";
	std::cout << "14 - Change password.\n15 - Change name.\n16 - Log out\n";

	while (true)
	{
		std::cout << "-> Enter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice >= 1 && userChoice <= 16)
		{
			return static_cast<UserChoice>(userChoice);
		}
		else
		{
			std::cout << "-! Wrong choice, enter again\n";
		}
	}
}

nlohmann::json Rector::to_json()
{
	nlohmann::json rectorJson;

	rectorJson["name"] = name;
	rectorJson["password"] = password;
	rectorJson["id"] = id;
	
	return rectorJson;
}

void Rector::from_json(nlohmann::json& rectorJson)
{
	name = rectorJson["name"];
	password = rectorJson["password"];
	id = rectorJson["id"];
}



