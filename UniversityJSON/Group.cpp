#include "Group.h"

void Group::AddStudent(Student& student)
{
	students.push_back(student);
}

void Group::DeleteStudent(Student& student)
{
	students.remove(student);
}

void Group::ShowInfo()
{
	std::cout << " - - Group - -\n Id: " << id << std::endl;

	if (!students.empty())
	{
		for (auto it = students.begin(); it != students.end(); it++)
		{
			(*it).ShowInfo();
		}
	}
	else
	{
		std::cout << " - - Students Empty - - \n";
	}
}

nlohmann::json Group::to_json()
{
	nlohmann::json groupJson;

	groupJson["id"] = id;
	for (Student& student : students)
	{
		groupJson["students"].push_back(student.to_json());
	}

	return groupJson;
}

void Group::from_json(nlohmann::json& groupJson)
{
	id = groupJson["id"];
	students.clear(); 
	for (auto& studentJson : groupJson["students"])
	{
		Student student;
		student.from_json(studentJson);
		students.push_back(student);
	}
}


