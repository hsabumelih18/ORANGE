#include <iostream>
#include <string>
#include <vector>
#include "functions.h"
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
	notArchived,
};

struct STUDENT_DATA
{
	string name;
	string surname;
	int klas;
	ROLE role;
	string email;
};

struct TEACHER_DATA
{
	string name;
	string surname;
	vector <string> teams;
	string email;
};

struct TEAM_DATA
{
	string name;
	string description;
	string setUpDate;
	vector <STUDENT_DATA> students;
	TEAM_STATUS status;
	TEACHER_DATA teacher;
};

struct SCHOOL_DATA
{
	string name;
	string city;
	string address;
	vector <TEACHER_DATA> teachers;
	vector <TEAM_DATA> teams;
	vector <STUDENT_DATA> students;
};