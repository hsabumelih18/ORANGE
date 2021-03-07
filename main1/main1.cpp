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
	int choices[3] = { -1, -1, -1 };
	do
	{
		choices[0] = menus(0, choices);
		if (choices[0] != 0)
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
						addElement(schoolData, choices);
						cout << "Successfully added new element!" << endl;
						break;
					}
					case 2:
					{
						if (choices[1] < 3) { choices[2] = menus(2, choices); }
						else { choices[2] = menus(3, choices); }
						break;
					}
					case 3:
					{
						//edit stuff
					}
					case 4:
					{
						//write into file
					}
					case 5:
					{
						credits();
					}
					default:
					{
						cout << "Invalid input" << endl;
					}
					}
				}
			}
			choices[1] = -1;
		}
	} while (choices[0] != 0);
}

//to do
//try catch thingies (idk)
//choice layer thing (almost)
//file writing thing (can someone else do it pls)
//front end (not my job lol)
//making sure shit doesn't break (oh boy)