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
						if (addElement(schoolData, choices)) { cout << "NOTIFICATION: Successfully added new element!" << endl; }
						else { cout << "No element has been added." << endl; }
						break;
					}
					case 2:
					{
						if (editElements(schoolData, choices)) { cout << "NOTIFICATION: Bravo! Elements successfully changed!" << endl; }
						else { cout << "NOTIFICATION: No element has been edited." << endl; }
						break;
					}
					case 3:
					{
						if (deleteElement(schoolData, choices)) { cout << "NOTIFICATION: Successfully deleted element!" << endl; }
						else { cout << "NOTIFICATION: No element has been deleted." << endl; }
						break;
					}
					case 4:
					{
						cout << "Choose file name (It'll create another file if it needs to) " << endl;
						cin >> fileName;
						if (writeInFile(fileName, schoolData, choices)) { cout << "NOTIFICATION: Successfully written in file!" << endl; }
						else { cout << "NOTIFICATION: Nothing was written in a file." << endl; }
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