#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
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
	string name = "No name";
	string surname = "No surname";
	int klas = 0;
	ROLE role = ROLE::noRole;
	string email = "No email";
};

struct TEACHER_DATA
{
	string name = "No name";
	string surname = "No surname";
	vector <string> teams = { "No teams yet." };
	string email = "No email";
};

struct TEAM_DATA
{
	string name = "No name";
	string description = "No description yet";
	string setUpDate = "set up date";
	vector <STUDENT_DATA> students;
	TEAM_STATUS status = TEAM_STATUS::inUse;
	TEACHER_DATA teacher;
};

struct SCHOOL_DATA
{
	string name = "No name";
	string city = "No city";
	string address = "No address";
	vector <TEACHER_DATA> teachers;
	vector <TEAM_DATA> teams;
	vector <STUDENT_DATA> students;
};

string getTime();
int testInt();
int menus(int menu, int* choices);
void credits();
bool addElement(SCHOOL_DATA& schoolData, int* choices);
bool editTeams(SCHOOL_DATA& schoolData);
bool editElements(SCHOOL_DATA& schoolData, int* choices);
bool deleteElement(SCHOOL_DATA& schoolData, int* choices);
bool writeInFile(string fileName, SCHOOL_DATA& schoolData, int* choices);
string roleToString(ROLE role);
bool inputFileNames();
bool checkInUse(TEAM_STATUS status);