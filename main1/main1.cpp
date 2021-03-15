#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include <ctime>
using namespace std;
int main()
{
	SCHOOL_DATA schoolData;
	string fileName;
	bool loopUntilOne = 0;
	do
	{
		loopUntilOne = inputFileNames();
		if (loopUntilOne) { cout << "Successfully created all files" << endl; }
		else { cout << "Some error occured while creating the files" << endl; }
	} while (!loopUntilOne);

	bool editSuccess = 0;
	int choices[2] = { -1, -1 };
	do
	{
		choices[0] = menus(0, choices);
		if (choices[0] != 0 and choices[0] != 5)
		{
			while (choices[1] != 0)
			{
				choices[1] = menus(1, choices);
				if (choices[1] != 0)
				{
					switch (choices[0])
					{
					case 1:
					{
						if (addElement(schoolData, choices)) { cout << "Successfully added new element!" << endl; }
						else { cout << "No element has been added." << endl; }
						break;
					}
					case 2:
					{
						if (editElements(schoolData, choices)) { cout << "Bravo! Team data successfully changed!" << endl; editSuccess = 1; }
						else { cout << "No element has been edited." << endl; }
						break;
					}
					case 3:
					{
						if (deleteElement(schoolData, choices)) { cout << "Successfully deleted element!" << endl; }
						else { cout << "No element has been deleted." << endl; }
						break;
					}
					case 4:
					{
						cout << "Choose file name (It'll create another file if it needs to) " << endl;
						cin >> fileName;
						if (writeInFile(fileName, schoolData, choices)) { cout << "Successfully written in file!" << endl; }
						else { cout << "Nothing was written in a file." << endl; }
						break;
					}
					default:
					{
						cout << "Invalid input" << endl;
						break;
					}
					}
				}
			}
			choices[1] = -1;
		}
		else
		{
			credits();
		}
	} while (choices[0] != 0);
}

//to do
//try catch thingies (idk)
//choice layer thing (almost)
//file writing thing (can someone else do it pls)
//front end (not my job lol)
//making sure shit doesn't break (oh boy)