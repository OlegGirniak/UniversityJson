#include "University.h"

nlohmann::json University::to_json()
{
    nlohmann::json universityJson;
    universityJson["rector"] = rector.to_json();

    for (Teacher& teacher : teachers)
    {
        universityJson["teachers"].push_back(teacher.to_json());
    }

    for (Group& group : groups)
    {
        universityJson["groups"].push_back(group.to_json());
    }

    return universityJson;
}

void University::from_json(nlohmann::json& universityJson)
{
    rector.from_json(universityJson["rector"]);

    teachers.clear();
    for (auto& teacherJson : universityJson["teachers"])
    {
        Teacher teacher;
        teacher.from_json(teacherJson);
        teachers.push_back(teacher);
    }

    groups.clear(); 
    for (auto& groupJson : universityJson["groups"])
    {
        Group group;
        group.from_json(groupJson);
        groups.push_back(group);
    }
}
