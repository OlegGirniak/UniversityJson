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

void Group::to_json(nlohmann::json& j)
{
	j = nlohmann::json{
		{"id", id},
		{"students", nlohmann::json::array()}
	};

	for (auto& student : students)
	{
		nlohmann::json studentJson;
		student.to_json(studentJson);
		j["students"].push_back(studentJson);
	}

}

void Group::from_json(nlohmann::json& j, int indexOfgroup)
{
	id = j["groups"][indexOfgroup]["id"];

	for (auto& studentJson : j["groups"][indexOfgroup]["students"]) {
		Student student;
		student.from_json(studentJson);
		students.push_back(student);
	}
}


