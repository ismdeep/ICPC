#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

string colorInstruction = "color 80";

void iChangeColor(int background, int colorValue)
{
	if (background == 1 || background == 2)
	{
		colorInstruction[6] = ('8' + background);
	}
	else
	{
		colorInstruction[6] = ('A' + background - 3);
	}
	colorInstruction[7] = ('0' + colorValue);
	system(&colorInstruction[0]);
}

int main()
{
	int background = rand() % 2;
	while (1)
	{
		if (rand() % 2 == 0)
		{
			background = rand() % 8;
		}
		iChangeColor(background , rand() % 8);
		Sleep(rand() % 50);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//
//
