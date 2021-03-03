#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum ROLE
{
	noRole,
	sTrainer,
	qaEngineer,
	backEnd,
	frontEnd
};

enum TEAM_STATUS
{
	inUse,
	notActive,
	archived,
};

struct STUDENT_DATA
{
	string name = "name";
	string surname = "surname";
	int klas = 0;
	ROLE role = noRole;
	string email = "email";
};

struct TEACHER_DATA
{
	string name = "name";
	string surname = "surname";
	vector <string> teams = { "No teams yet." };
	string email = "email";
};

struct TEAM_DATA
{
	string name = "name";
	string description = "description";
	string setUpDate = "set up date";
	vector <STUDENT_DATA> students;
	TEAM_STATUS status = inUse;
	TEACHER_DATA teacher;
};

struct SCHOOL_DATA
{
	string name = "name";
	string city = "city";
	string address = "address";
	vector <TEACHER_DATA> teachers;
	vector <TEAM_DATA> teams;
	vector <STUDENT_DATA> students;
};

vector <vector <string>> MENU_ITEMS
{
	{
		{ "1. Add elements" },
		{ "2. Edit elements" },
		{ "3. Delete elements" },
		{ "4. Write elements in a .txt file" },
		{ "0. Exit program" }
	},
	{
		{ "1. Teacher" },
		{ "2. Student" },
		{ "3. Team" },
		{ "4. School" },
		{ "0. Go back" }
	},
	{
		{ "1. Edit name" },
		{ "2. Edit surname" },
		{ "3. Edit email" },
		{ "4. Edit role" },
		{ "5. Edit class" },
		{ "0. Go back" }
	},
	{
		{ "1. Add students" },
		{ "2. Change students" },
		{ "3. Add/Change teacher" },
		{ "0. Go back" }
	}
};

int menus(int menu, int* choices)
{
	int choice;
	try
	{
		for (size_t i = 0; i < MENU_ITEMS[menu].size(); i++)
		{
			if (menu == 0 | menu == 3) { cout << MENU_ITEMS[menu][i] << endl; }
			if (menu == 1)
			{
				if (i != 4 | choices[0] == 4) { cout << MENU_ITEMS[menu][i] << endl; }
			}
			if (menu == 2)
			{
				if (choices[1] == 2 | (i != 3 && i != 4)) { cout << MENU_ITEMS[menu][i] << endl; }
			}
		}
	}
	catch (...)
	{
		system("CLS");
		cout << "Invalid input" << endl;
		return -1;
	}
	try
	{
		cin >> choice;
	}
	catch (...)
	{
		system("CLS");
		cout << "Wrong data type input" << endl;
		return -1;
	}

	return choice;
}

void addElement(SCHOOL_DATA& schoolData, int* choices)
{
	switch (choices[1])
	{
	case 0: schoolData.teachers.push_back({ "name", "surname", {"No teams yet."}, "email" }); break;
	case 1: schoolData.students.push_back({ "name", "surname", 0, noRole, "email" }); break;
	case 2: schoolData.teams.push_back({ "name", "description", "set up date" }); break;
	default: cout << "Invalid Input" << endl; break;
	}
}