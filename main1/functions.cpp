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
		{ "|-------------[ MENU ]-------------|" },
		{ "| 1. Add elements                  |" },
		{ "| 2. Edit elements                 |" },
		{ "| 3. Delete elements               |" },
		{ "| 4. Write elements in a .txt file |" },
		{ "| 5. Credits                       |" },
		{ "| 0. Exit program                  |" },
		{ "|----------------------------------|" }
	},
	{
		{ "|--[ MENU ]--|" },
		{ "| 1. Teacher |" },
		{ "| 2. Student |" },
		{ "| 3. Team    |" },
		{ "| 4. School  |" },
		{ "| 0. Go back |" },
		{ "|------------|" }
	},
	{
		{ "|----[ MENU ]-----|" },
		{ "| 1. Edit name    |" },
		{ "| 2. Edit surname |" },
		{ "| 3. Edit email   |" },
		{ "| 4. Edit role    |" },
		{ "| 5. Edit class   |" },
		{ "| 0. Go back      |" },
		{ "|-----------------|" }
	},
	{
		{ "|-------[ MENU ]--------|" },
		{ "| 1. Add students       |" },
		{ "| 2. Change students    |" },
		{ "| 3. Add/Change teacher |" },
		{ "| 0. Go back            |" },
		{ "|-----------------------|" }
	},
		{
		{ "|----------[ MENU ]----------|" },
		{ "| 1. Write teachers in file  |" },
		{ "| 2. Write students in file  |" },
		{ "| 3. Write teams in file     |" },
		{ "| 0. Go back                 |" },
		{ "|----------------------------|" }
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

string getTime()
{
	string info;
	time_t now = time(0);
	string dt = ctime(&now);
	info = "The last update was made at: " + dt;
	return info;
}

int menus(int menu, int* choices)
{
	int choice;
	try
	{
		for (size_t i = 0; i < MENU_ITEMS[menu].size(); i++)
		{
			if (menu == 0 || menu == 3 || menu == 4) { 
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
	cout << "Enter your choice: ";
	choice = testInt();
	system("CLS");
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

void showAllTeamsElements(SCHOOL_DATA& schoolData)
{
	TEAM_DATA team;
	cout << getTime();
	for (size_t i = 0; i < schoolData.teams.size(); i++)
	{
		team = schoolData.teams[i];
		if (checkInUse(team.status))
		{
			cout << "File: " << team.name;
		}
		else continue;
		cout << "Team's description: " <<team.description << endl;
		cout << "This team was set up at: " << team.setUpDate << endl;
		cout << "The teacher in this team is:" << endl;
		cout << team.teacher.name << endl;
		cout << "Students in this team are:" << endl;
		for (size_t j = 0; j < team.students.size(); j++)
		{
			cout << j << ". " << team.students[j].name << endl;
		}
		cout << "---------------------------------------------------------------";
	}
}

string roleToString(ROLE role)
{
	switch (role)
	{
	case sTrainer:
		return "Scrum Trainer";
	case qaEngineer:
		return "QA Engineer";
	case backEnd:
		return "Back End Developer";
	case frontEnd:
		return "Front End Developer";
	case noRole:
		return "NO ROLE";
	default:
		return "ERROR";
	}
}

string statusToString(TEAM_STATUS status)
{
	switch (status)
	{
	case inUse:
		return "IN USE";
	case notActive:
		return "NOT ACTIVE";
	case archived:
		return "ARCHIVED";
	default:
		return "ERROR";
	}
}

void showAllTeacherElements(SCHOOL_DATA& schoolData)
{
	TEACHER_DATA teacher;
	cout << getTime();
	for (size_t i = 0; i < schoolData.teachers.size(); i++)
	{
		teacher = schoolData.teachers[i];
		cout << i << ". " << teacher.name << teacher.surname<<endl;
		cout << "                " << teacher.email <<endl;
		cout << "Teams:"<<endl;
		for (size_t j = 0; j < teacher.teams.size(); j++)
		{
			cout << "  " << j <<". "<< teacher.teams[j];
		}
	}

}

void showAllStudentElements(SCHOOL_DATA& schoolData)
{
	STUDENT_DATA student;
	cout << getTime();
	for (size_t i = 0; i < schoolData.students.size(); i++)
	{
		student = schoolData.students[i];
		cout << i << ". " << student.name << student.surname <<" class" << student.klas << endl;
		cout << "                " << student.email << "Role: " << roleToString(student.role);
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

bool addElement(SCHOOL_DATA& schoolData, int* choices)
{
	switch (choices[1])
	{
	case 1: 
	{
		schoolData.teachers.push_back({ "name", "surname", {"No teams yet."}, "email" }); 
		return 1;
	}
	case 2: 
	{
		schoolData.students.push_back({ "name", "surname", 0, ROLE::noRole, "email" }); 
		return 1; 
	}
	case 3: 
	{
		schoolData.teams.push_back({ "name", "description", "set up date" }); 
		teamStatusSwitch(schoolData, schoolData.teams.size());
		return 1;
	}
	default:
	{
		cout << "Invalid Input" << endl;
		return 0;
	}
	}
}

bool editTeams(SCHOOL_DATA& schoolData)
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
		cout << "Your choice: ";
		cin >> choiceTeam;
		if (choiceTeam > schoolData.teams.size()) {
			cout << "Invalid team index" << endl;
		}
		else {
			showAllTeamsElements(schoolData);
			cout << "Your choice: ";
			cin >> choiceElement;
			switch (choiceElement)
			{
			case 1:
			{
				cout << "Enter the team's new name: ";
				cin >> schoolData.teams[choiceTeam - 1].name;
				cout << endl;
				return 1;
			}
			case 2: {
				cout << "Enter the team's new description: ";
				cin >> schoolData.teams[choiceTeam - 1].description; 
				cout << endl;
				return 1;
			}
			case 3: 
			{
				cout << "Enter the team's new set up date: ";
				cin >> schoolData.teams[choiceTeam - 1].setUpDate;
				cout << endl;
				return 1;
			}
			case 4: 
			{
				cout << "Enter the team's new teacher name: ";
				cin >> schoolData.teams[choiceTeam - 1].teacher.name;
				cout << endl;
				return 1;
			}
			case 0: return 0;
			default: cout << "Hmm... Something went wrong, please try entering a value between 0 and 4! " << endl; return 0;
			}
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
	return 0;
}

bool editStudents(SCHOOL_DATA& schoolData, int choice)
{
	showAllStudentElements(schoolData);
	int choiceIndex;
	cin >> choiceIndex;

	return 0;
}

bool editTeachers(SCHOOL_DATA& schoolData, int choice)
{
	return 0;
}

bool editElements(SCHOOL_DATA& schoolData, int* choices)
{
	int choice;
	try
	{
		switch (choices[1])
		{
		case 1: choice = menus(2, choices);
		case 2: choice = menus(2, choices);
		case 3: choice = menus(3, choices);
		case 0: return 0;
		default: return 0;
		}

		switch (choice)
		{
		case 1: if (editTeachers(schoolData, choice)) { return 1; } break;
		case 2: if (editStudents(schoolData, choice)) { return 1; } break;
		case 3: if (editTeams(schoolData)) { return 1; } break;
		case 0: return 0;
		default: return 0;
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
	return 0;
}

bool deleteElement(SCHOOL_DATA& schoolData, int* choices)
{
	int choice;
	try
	{
		cout << "This is the delete element function!" << endl << endl;
		switch (choices[1])
		{
		case 1: showAllTeacherElements(schoolData); break;
		case 2: showAllStudentElements(schoolData); break;
		case 3: showAllTeamsElements(schoolData); break;
		default: cout << "Invalid choice" << endl; return 0;
		}
		cout << "Enter the index of the element you want to erase!" << endl;
		cout << "Your input: ";
		cin >> choice;
		switch (choices[1])
		{
		case 1: 
		{
			if (!schoolData.teachers.empty())
			{
				vector<TEACHER_DATA>::iterator it = schoolData.teachers.begin();
				advance(it, choice);
				if (it <= schoolData.teachers.end())
				{
					schoolData.teachers.erase(it);
					return 1;
				}
			}
			return 0;
		}
		case 2: 
		{
			if (!schoolData.students.empty())
			{
				vector<STUDENT_DATA>::iterator it = schoolData.students.begin();
				advance(it, choice);
				if (it <= schoolData.students.end())
				{
					schoolData.students.erase(it);
					return 1;
				}
			}
			return 0;
		}
		case 3:
		{
			if (!schoolData.teams.empty())
			{
				vector<TEAM_DATA>::iterator it = schoolData.teams.begin();
				advance(it, choice);
				if (it <= schoolData.teams.end())
				{
					schoolData.teams.erase(it);
					return 1;
				}
			}
			return 0;
		}
		case 0: return 0;
		default: 
		{
			cout << "Invalid choice" << endl;
			return 0;
		}
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
	return 0;
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
	fileName = fileName + ".txt";

	file.open(fileName, ios::out | ios::trunc);

	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}

bool deleteFile(string fileName)
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

int renameFile(string oldFileName, string newFileName)
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

void fcreateFile(string fileName)
{
	if (checkFile(fileName) == 0)
	{
		createFile(fileName);
	}
	else cout << "The file you are trying to create already exists!";
}

bool nameFiles(string students, string teachers, string teams)
{
	fcreateFile(students);
	fcreateFile(teachers);
	fcreateFile(teams);
	if (checkFile(teams) == 0 && checkFile(students) == 0 && checkFile(teachers) == 0)
	{
		return 1;
	}
	else return 0;
}

bool inputFileNames()
{
	string students, teachers, teams;
	cout << "Before starting, you'll have to create your student, teacher and team .txt files that will contain all your students, teachers and teams" << endl;
	cout << "Let's begin with the student's file\n"<<endl;
	cout << "Enter a suitable name for the file: ";
	cin >> students;
	cout << endl;
	cout << "Now for the teacher's file: ";
	cin >> teachers;
	cout << endl;
	cout << "And lastly a file for all the teams: ";
	cin >> teams;
	cout << endl;
	return nameFiles(students, teachers, teams);
}

void showFileContents()
{
	string fileContents;
	ifstream MyReadFile("filename.txt");
	while (getline(MyReadFile, fileContents)) {
		
		cout << fileContents;
	}

}

void writeTeamsInFile(string fileName, SCHOOL_DATA& schoolData)
{
	TEAM_DATA team;
	ofstream file;
	file << getTime();
	file.open(fileName, ios::in | ios::trunc);
	for (size_t i = 0; i < schoolData.teams.size(); i++)
	{
		team = schoolData.teams[i];
		if (checkInUse(team.status))
		{
			cout << "File: " << team.name;
		}
		else continue;
		file << "Team's description: " << team.description << endl;
		file << "This team was set up at: " << team.setUpDate << endl;
		file << "The teacher in this team is:" << endl;
		file << team.teacher.name << endl;
		file << "Students in this team are:" << endl;
		for (size_t j = 0; j < team.students.size(); j++)
		{
			file << j << ". " << team.students[j].name << endl;
		}
		file << "---------------------------------------------------------------";
	}
}

void writeTeachersInFile(string fileName, SCHOOL_DATA& schoolData)
{
	TEACHER_DATA teacher;
	ofstream file;
	file << getTime();
	file.open(fileName, ios::in | ios::trunc);
	for (size_t i = 0; i < schoolData.teachers.size(); i++)
	{
		teacher = schoolData.teachers[i];
		file << i << ". " << teacher.name << teacher.surname << endl;
		file << "                " << teacher.email << endl;
		file << "Teams:" << endl;
		for (size_t j = 0; j < teacher.teams.size(); j++)
		{
			file << "  " << j << ". " << teacher.teams[j];
		}
	}
	file.close();
}

void writeStudentsInFile(string fileName, SCHOOL_DATA& schoolData)
{
	STUDENT_DATA student;
	ofstream file;
	fileName = fileName + ".txt";
	file.open(fileName, ios::in | ios::trunc);
	file << getTime();
	for (size_t i = 0; i < schoolData.students.size(); i++)
	{
		student = schoolData.students[i];
		file << i << ". " << student.name << student.surname << " class" << student.klas << endl;
		file << "                " << student.email << "Role: " << roleToString(student.role);
	}
	file.close();
}

bool writeInFile(string fileName, SCHOOL_DATA& schoolData, int* choices)
{
	int choice;
	try
	{
		if (!checkFile(fileName))
		{
			fcreateFile(fileName);
		}
		choice = menus(4, choices);
		switch (choices[1])
		{
		case 1:
		{
			writeTeachersInFile(fileName, schoolData);
			return 1;
		}
		case 2:
		{
			writeStudentsInFile(fileName, schoolData);
			return 1;
		}
		case 3:
		{
			writeTeamsInFile(fileName, schoolData);
			return 1;
		}
		case 0: return 0;
		default:
		{
			cout << "Hmm... Something went wrong! Please try entering a value between 0 and 3!" << endl;
			return 0;
		}
		}
	}
	catch (...)
	{
		cout << "Error: Incorrect data input" << endl;
	}
	return 0;
}

void credits()
{
	cout << endl;
	cout << "|------------------------------------------|\n";
	cout << "| Scrum Trainer:          Hussein Abumelih |\n";
	cout << "| C++ Developer:	         Teodor Angelov |\n";
	cout << "| Front End Developer:    Stephan Stratev  |\n";
	cout << "| QA Engineer:            Alexander Yanev  |\n";
	cout << "|------------------------------------------|\n";
	cout << endl;
}