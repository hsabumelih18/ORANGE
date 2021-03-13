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

bool checkInUse(TEAM_STATUS status)
{
	if (status == inUse)
	{
		return true;
	}
	return false;
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
		cout << "Team's description: " << schoolData.teams[i].description << endl;
		cout << "This team was set up at: " << schoolData.teams[i].setUpDate << endl;
		cout << "The teacher in this team is:" << endl;
		cout << schoolData.teams[i].teacher.name << endl;
		cout << "Students in this team are:" << endl;
		for (int j = 0; j < schoolData.teams[i].students.size(); j++)
		{
			cout << j << ". " << schoolData.teams[i].students[j].name << endl;
		}
	}
}

void teamStatusSwitch(SCHOOL_DATA& schoolData, size_t usedTeamIndex)
{
	for (size_t i = 0; i < schoolData.teams.size(); i++)
	{
		if (i == usedTeamIndex)
		{
			schoolData.teams[i].status = inUse;
		}
	}
}

void addElement(SCHOOL_DATA& schoolData, int* choices)
{
	switch (choices[1])
	{
	case 1: schoolData.teachers.push_back({ "name", "surname", {"No teams yet."}, "email" }); break;
	case 2: schoolData.students.push_back({ "name", "surname", 0, ROLE::noRole, "email" }); break;
	case 3: 
	{
		schoolData.teams.push_back({ "name", "description", "set up date" }); break;
		teamStatusSwitch(schoolData, schoolData.teams.size());
	}
	default: cout << "Invalid Input" << endl; break;
	}
}

void editTeams(SCHOOL_DATA& schoolData)
{
	size_t choiceTeam;
	size_t choiceElement;
	cout << "Choose a team to edit (0 to go back)" << endl;
	for (size_t i = 0; i < schoolData.teams.size(); i++)
	{
		cout << i + 1 << ". " << schoolData.teams[i].name << endl;
	}
	try
	{
		cin >> choiceTeam;
		if (choiceTeam > schoolData.teams.size()) {
			cout << "Invalid team index" << endl;
		}
		else {
			showElements(schoolData);
			cin >> choiceElement;
			switch (choiceElement)
			{
			case 1: cin >> schoolData.teams[choiceTeam - 1].name; break;
			case 2: cin >> schoolData.teams[choiceTeam - 1].description; break;
			case 3: cin >> schoolData.teams[choiceTeam - 1].setUpDate; break;
			case 4: cin >> schoolData.teams[choiceTeam - 1].teacher.name; break;
			case 0: break;
			default: cout << "Invalid option" << endl;
			}
			cout << "Team data successfully changed!" << endl;
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
}

void deleteElement(SCHOOL_DATA& schoolData, int* choices)
{
	int choice;
	try
	{
		cout << "Choose index to erase: " << endl;
		cin >> choice;
		switch (choices[1])
		{
		case 1: 
		{
			vector<TEACHER_DATA>::iterator it = schoolData.teachers.begin() + choice;
			if (it <= schoolData.teachers.end())
			{
				schoolData.teachers.erase(it);
			}
			break;
		}
		case 2: 
		{
			vector<STUDENT_DATA>::iterator it = schoolData.students.begin() + choice;
			if (it <= schoolData.students.end())
			{
				schoolData.students.erase(it);
			}
			break;
		}
		case 3:
		{
			vector<TEAM_DATA>::iterator it = schoolData.teams.begin() + choice;
			if (it <= schoolData.teams.end())
			{
				schoolData.teams.erase(it);
			}
			break;
		}
		case 0: break;
		default: cout << "Invalid choice" << endl;
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
}
bool checkFile(string fileName)
{
	ifstream file;

	file.open(fileName, ios::in | ios::_Nocreate);

	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;


}
bool createFile(string fileName)
{
	ofstream file;

	file.open(fileName, ios::out | ios::trunc);

	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}
bool deleteFile(std::string fileName)
{
	// 0 means success
	// != 0 means failure
	int result = remove(fileName.c_str());

	if (result != 0)
	{
		return errno;
	}
	return 0;
}
int renameFile(std::string oldFileName, std::string newFileName)
{
	// 0 means success
	// != 0 means failure
	int result = rename(oldFileName.c_str(), newFileName.c_str());

	if (result != 0)
	{
		return errno;
	}

	return 0;
}
void enterInfoInFiles(SCHOOL_DATA& schoolData)
{

}

void fcreateFile(string fileName)
{
	if (checkFile(fileName) == 0)
	{
		createFile(fileName);
	}
	else cout << "The file you are trying to create already exists!";
	if (checkFile(fileName)==0)
	{
		cout << "Hmmm... there is something wrong!";
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