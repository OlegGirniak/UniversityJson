#include "University.h"

void University::to_json(nlohmann::json& rectorJson, nlohmann::json& groupsJson, nlohmann::json& teachersJson)
{
	//rector
	rectorJson = nlohmann::json{
		{"rector", nlohmann::json::array()}
	};
	nlohmann::json tmpRectorJson;
	rector.to_json(tmpRectorJson);
	rectorJson["rector"].push_back(tmpRectorJson);

	//groups
	groupsJson = nlohmann::json{
		{"groups", nlohmann::json::array()}
	};
	for (auto& group : groups)
	{
		nlohmann::json groupJson;
		group.to_json(groupJson);
		groupsJson["groups"].push_back(groupJson);
	}

	//teachers
	teachersJson = nlohmann::json{
		{"teachers", nlohmann::json::array()}
	};
	for (auto& teacher : teachers)
	{
		nlohmann::json teacherJson;
		teacher.to_json(teacherJson);
		teachersJson["teachers"].push_back(teacherJson);
	}
}

void University::from_json(nlohmann::json& rectorJson, nlohmann::json& groupsJson, nlohmann::json& teachersJson)
{	
	rector.from_json(rectorJson);

	int indexOfGroup = 0;
	for (auto& groupJson : groupsJson["groups"])
	{
		Group group;
		group.from_json(groupJson, indexOfGroup++);
		groups.push_back(group);
	}

	int indexOfTeachers;


}

