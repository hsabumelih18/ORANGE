#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include <ctime>
using namespace std;

vector <vector <string>> MENU_ITEMS
{
	{
		{ "1. Add elements" },
		{ "2. Edit elements" },
		{ "3. Delete elements" },
		{ "4. Write elements in a .txt file" },
		{ "5. Credits"},
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

int testInt()
{
	int choice;
	while (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value! Try entering a whole number!" << endl;
	}
	return choice;
}
int menus(int menu, int* choices)
{
	int choice;
	try
	{
		for (size_t i = 0; i < MENU_ITEMS[menu].size(); i++)
		{
			if (menu == 0 || menu == 3) { 
				cout << MENU_ITEMS[menu][i] << endl; 
			}
			if (menu == 1){
				if (i != 3 || choices[0] == 4) { cout << MENU_ITEMS[menu][i] << endl; }
			}
			if (menu == 2){
				if (choices[1] == 2 || (i != 3 && i != 4)) { cout << MENU_ITEMS[menu][i] << endl; }
			}
		}
	}
	catch (...)
	{
		system("CLS");
		cout << "Invalid input" << endl;
		return -1;
	}
	choice = testInt();
	return choice;
}

void addElement(SCHOOL_DATA& schoolData, int* choices)
{
	switch (choices[1])
	{
	case 0: schoolData.teachers.push_back({ "name", "surname", {"No teams yet."}, "email" }); break;
	case 1: schoolData.students.push_back({ "name", "surname", 0, ROLE::noRole, "email" }); break;
	case 2: schoolData.teams.push_back({ "name", "description", "set up date"}); break;
	default: cout << "Invalid Input" << endl; break;
	}
}
bool checkInUse(TEAM_STATUS status)
{
	if (status == inUse)
	{
		return true;
	}
}
void showElements(SCHOOL_DATA& schoolData)
{
	cout << getTime();
	for (int i = 0; i < schoolData.teams.size(); i++)
	{
		if (checkInUse(schoolData.teams[i].status))
		{
			cout << "File: " << schoolData.teams[i].name;
		}
		else continue;
		cout << "Team's description: "<<schoolData.teams[i].description << endl;
		cout << "This team was set up at: " << schoolData.teams[i].setUpDate << endl;
		cout <<"The teacher in this team is:"<< endl;
		cout << schoolData.teams[i].teacher.name<<endl;
		cout << "Students in this team are:" << endl;
		for (int j = 0; j < schoolData.teams[i].students.size();j++)
		{
			cout << j << ". " << schoolData.teams[i].students[j].name<<endl;
		}
	}

}
void enterInfoInFiles(SCHOOL_DATA& schoolData)
{

}
void createFiles(SCHOOL_DATA& schoolData)
{
	for (int i = 0; i < schoolData.teams.size();i++)
	{
		if (checkInUse(schoolData.teams[i].status))
		{
			string name = schoolData.teams[i].name;
			ofstream MyWriteFile(name + ".txt");
		}
		else continue;
	}
}
void showFileContents()
{
	string fileContents;
	ifstream MyReadFile("filename.txt");
	while (getline(MyReadFile, fileContents)) {
		
		cout << fileContents;
	}

}
string getTime()
{
	string info;
	time_t now = time(0);
	string dt = ctime(&now);
	info = "The last update was made at: " + dt;
	return info;
}
void credits()
{
	cout << endl;
	cout << "Scrum Trainer:          Hussein Abumelih\n" << endl;
	cout << "C++ Developer:	         Teodor Angelov\n" << endl;
	cout << "Front End Developer:    Stephan Stratev\n" << endl;
	cout << "QA Engineer:            Alexander Yanev\n" << endl;
	cout << endl;
}