/*
 * Project     : Tower_of_Hanoi
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Oct  8 16:21:40 2012 
 *
 */

#include <iostream>
#include <cstdio>
using namespace std;

void show_operation (int id, char Source, char Destination)
{
	printf ("%d : %c -> %c \n", id, Source, Destination);
}


void move_hanoi (int n, char Source, char Temp, char Destination)
{
	if (n <= 1)
	{
		show_operation (n, Source, Destination);
	}
	else
	{
		move_hanoi (n-1, Source, Destination, Temp       );
		show_operation (n, Source, Destination);
		move_hanoi (n-1, Temp  , Source     , Destination);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n >= 1)
		{
			move_hanoi (n, 'A', 'B', 'C');
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

