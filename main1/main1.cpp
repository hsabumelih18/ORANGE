#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;

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
				addElement(schoolData, choices);
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