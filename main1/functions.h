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
	ROLE role = ROLE::noRole;
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
	TEAM_STATUS status = TEAM_STATUS::inUse;
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

int menus(int menu, int* choices);

void addElement(SCHOOL_DATA& schoolData, int* choices);