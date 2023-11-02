#pragma once
#include <iostream>
#include "UserChoice.h"


class Person
{
protected:
	std::string name;
	std::string password;
	unsigned id;

public:
	Person() : name(""), password(""), id(0) { }
	Person(std::string name, std::string password, unsigned id) : name(name), password(password), id(id) { }

	void SetName(std::string name) { this->name = name; }
	void SetPassword(std::string password) { this->password = password; }
	void SetId(unsigned id) { this->id = id; }

	std::string GetName() const { return name; }
	std::string GetPassword() const { return password; }
	unsigned GetId() const { return id; }

	void ShowInfo();

	virtual UserChoice Menu() { return UserChoice::ShowAllInformation; }
};
