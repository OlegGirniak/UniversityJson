#include <iostream>
#include <string>
#include <fstream>
#include "University.h"
#include "Profession.h"	

std::pair<Profession, unsigned> LogIn(Rector& rector, std::list<Teacher>& teachers, std::list<Group>& groups);

nlohmann::json SerialiseInJson(University& university, std::string file);
void DeserialiseFromJson(University& university, std::string file);

int main()
{
	University university;

	DeserialiseFromJson(university, "Main.json");

	while (true)
	{
		std::cout << "1 - Log In\n 2 - Exit\nEnter choice: ";
		int userChoice;
		std::cin >> userChoice;

		if (userChoice == 1)
		{
			auto userData = LogIn(university.GetRector(), university.GetTeachers(), university.GetGroups());

			bool ifLogOut = false;
			while (!ifLogOut)
			{
				switch (userData.first)
				{
				case Profession::Rector:
				{
					Rector& user = university.GetRector();

					switch (user.Menu())
					{
					case UserChoice::AddGroup:
						user.AddGroup(university.GetGroups());

						break;

					case UserChoice::AddTeacher:
						user.AddTeacherInUniversity(university.GetTeachers());

						break;

					case UserChoice::AddStudentInGroup:
						user.AddStudentInGroup(university.GetGroups());

						break;

					case UserChoice::AddMarkForStudent:
						user.AddMarkForStudent(university.GetGroups());

						break;

					case UserChoice::AddGroupforTeacher:
						user.AddGroupForTeacher(university.GetTeachers(), university.GetGroups());

						break;

					case UserChoice::ShowAllInformation:
						user.ShowAllInformation(university.GetGroups(), university.GetTeachers());

						break;

					case UserChoice::ShowGroupInformation:
						user.ShowGroupInformationById(university.GetGroups());

						break;

					case UserChoice::ShowStudentInformation:
						user.ShowStudentInformationById(university.GetGroups());

						break;

					case UserChoice::ShowTeacherInformation:
						user.ShowTeacherInformationById(university.GetTeachers());

						break;

					case UserChoice::DeleteGroup:
						user.DeleteGroup(university.GetGroups());

						break;

					case UserChoice::DeleteTeacher:
						break;

					case UserChoice::DeleteStudent:
						break;

					case UserChoice::DeleteMarkForStudent:
						break;

					case UserChoice::ChangePassword:

						user.ChangePassword();
						break;
					case UserChoice::ChangeName:

						user.ChangeName();
						break;
					case UserChoice::LogOut:

						ifLogOut = true;
						break;
					default:
						break;
					}
				}

				break;
				case Profession::Teacher:
				{
					std::cout << "teacher";
				}

				break;
				case Profession::Student:
				{
					std::cout << "student";
				}

				break;
				default:
					break;
				}
			}
		}
		else if(userChoice == 2)
		{
			break;
		}
		else
		{
			std::cout << "Wrong choice, enter again.\n";
			system("pause");
			system("cls");
		}
	}

	//SerialiseInJson(university, "Main.json");

}

std::pair<Profession, unsigned> LogIn(Rector& rector, std::list<Teacher>& teachers, std::list<Group>& groups) 
{

	while (true)
	{
		std::cout << "\t-> Enter password: ";
		std::string inputPassword;
		std::cin >> inputPassword;

		if (inputPassword == rector.GetPassword())
		{
			return std::pair<Profession, unsigned>(Profession::Rector, rector.GetId());
		}
		
		for (auto teacher = teachers.begin(); teacher != teachers.end(); teacher++)
		{
			if (inputPassword == (*teacher).GetPassword())
			{
				return std::pair<Profession, unsigned>(Profession::Teacher, (*teacher).GetId());
			}
		}

		for (auto group = groups.begin(); group != groups.end(); group++)
		{
			for (auto student = (*group).GetStudents().begin(); student != (*group).GetStudents().end(); student++)
			{
				if (inputPassword == (*student).GetPassword())
				{
					return std::pair<Profession, unsigned>(Profession::Student, (*student).GetId());
				}
			}
		}

		std::cout << "\t -! Inncorrect password, enter again\n";
	}
}

nlohmann::json SerialiseInJson(University& university, std::string file)
{
	nlohmann::json universityJson = university.to_json();

	std::ofstream fileJson(file);

	fileJson << universityJson.dump();

	return universityJson;
}

void DeserialiseFromJson(University& university, std::string file)
{
	std::ifstream fileJson(file);
	std::string jsonStr;

	fileJson >> jsonStr;
	nlohmann::json universityJson = nlohmann::json::parse(jsonStr);
	
	university.from_json(universityJson);
}




/*
std::pair<Profession, unsigned> userData = LogIn(university.GetRector(), university.GetTeachers(), university.GetGroups());

	switch (userData.first)
	{
	case Profession::Rector:
	{
		Rector& user = university.GetRector();

		bool ifExit = false;

		while (!ifExit)
		{

			switch (user.Menu())
			{
			case UserChoice::AddGroup:
			{
				system("cls");
				user.AddGroup(university.GetGroups());
			}
			break;
			case UserChoice::AddTeacherInUniversity:
			{
				system("cls");
				user.AddTeacherInUniversity(university.GetTeachers());
			}
			break;
			case UserChoice::AddStudentInGroup:
			{
				system("cls");
				user.AddStudentInGroup(university.GetGroups());
			}
			break;
			case UserChoice::AddMarkForStudent:
			{
				system("cls");
				user.AddMarkForStudent(university.GetGroups());
			}
			break;
			case UserChoice::ShowAllInformation:
			{
				system("cls");
				user.ShowAllInformation(university.GetGroups(), university.GetTeachers());
			}
			break;
			case UserChoice::ShowGroupInformationById:
			{
				system("cls");
				user.ShowGroupInformationById(university.GetGroups());
			}
			break;
			case UserChoice::ShowTeacherInformationById:
			{
				system("cls");
				user.ShowTeacherInformationById(university.GetTeachers());
			}
			break;
			case UserChoice::ShowStudentInformationById:
			{
				system("cls");
				user.ShowStudentInformationById(university.GetGroups());
			}
			break;
			case UserChoice::DeleteGroup:
			{
				system("cls");
				user.DeleteGroup(university.GetGroups());
			}
			break;
			case UserChoice::DeleteTeacher:
			{
				system("cls");
				user.DeleteTeacher(university.GetTeachers(), university.GetGroups());
			}
			break;
			case UserChoice::DeleteStudent:
			{
				system("cls");
				user.DeleteStudent(university.GetGroups());
			}
			break;
			case UserChoice::DeleteMarkForStudent:
			{
				system("cls");
				user.DeleteMarkForStudent(university.GetGroups());
			}
			break;
			case UserChoice::Exit:
			{
				ifExit = true;
			}
			break;
			default:
			{
				std::cout << "Something get wrong\n";
			}
				break;
			}
		}
	}
	break;

	case Profession::Teacher:
	{
		Teacher& user = *(university.GetTeachers().begin());

		for (auto teacher = university.GetTeachers().begin(); teacher != university.GetTeachers().end(); teacher++)
		{
			if (userData.second == (*teacher).GetId())
			{
				user = *teacher;
				break;
			}
		}

		bool ifExit = false;

		while (!ifExit)
		{
			switch (user.Menu())
			{

			case UserChoice::AddMarkForStudent:
			{
				system("cls");
				user.AddMarkForStudent();
			}
			break;

			case UserChoice::ShowGroupInformationById:
			{
				system("cls");
				user.ShowGroupInformation();
			}
			break;

			case UserChoice::ShowStudentInformationById:
			{
				system("cls");
				user.ShowStudentInformation();
			}
			break;

			case UserChoice::DeleteMarkForStudent:
			{
				system("cls");
				user.DeleteMarkForStudent();
			}
			break;
			case UserChoice::Exit:
			{
				ifExit = true;
			}
			break;
			default:
			{
				std::cout << "Something get wrong\n";
			}
			break;
			}
		}
	}
	break;
	case Profession::Student:
	{
		auto group = (university.GetGroups().begin());
		Student& user = *((*group).GetStudents().begin());

		for (auto group = university.GetGroups().begin(); group != university.GetGroups().end(); group++)
		{
			for (auto student = (*group).GetStudents().begin(); student != (*group).GetStudents().end(); student++)
			{
				if (userData.second == (*student).GetId())
				{
					 user = *student;
				}
			}
		}

		bool ifExit = false;

		while (!ifExit)
		{
			switch (user.Menu())
			{

			case UserChoice::ShowStudentInformationById:
			{
				user.ShowInfo();
			}
			break;

			case UserChoice::Exit:
			{
				ifExit = true;
			}
			break;
			default:
			{
				std::cout << "Something get wrong\n";
			}
			break;
			}
		}
	}
	break;
	default:
		break;
	}
*/