#include <iostream>
#include <fstream>
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

int main()
{
	SCHOOL_DATA schoolData;
	int choices[3] = { -1, -1, -1 };
	do
	{
		choices[0] = menus(0, choices);
		do
		{
			choices[1] = menus(1, choices);
			switch (choices[0])
			{
			case 0:
			{

			}
			case 1:
			{
				if (choices[1] < 3) { choices[2] = menus(2, choices); }
				else { choices[2] = menus(3, choices); }
			}
			}
		} while (choices[1] != 0);
	} while (choices[0] != 0);
}

//to do
//try catch thingies (idk)
//choice layer thing (almost)
//file writing thing (can someone else do it pls)
//front end (not my job lol)
//making sure shit doesn't break (oh boy)

//Scratch all that, I give up