#pragma once

enum class UserChoice
{
	// add
	AddGroup = 1,
	AddTeacher,
	AddStudentInGroup,
	AddMarkForStudent,
	AddGroupforTeacher,

	//show
	ShowAllInformation,
	ShowGroupInformation,
	ShowStudentInformation,
	ShowTeacherInformation,

	//delete
	DeleteGroup,
	DeleteTeacher,
	DeleteStudent,
	DeleteMarkForStudent,

	//change
	ChangePassword,
	ChangeName,

	LogOut
};

