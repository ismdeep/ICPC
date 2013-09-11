// Project name : 1049 ( Climbing Worm ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 18:50:46 2012


#include <iostream>
using namespace std;

const bool goup   = true;
const bool godown = false;

void CCalClimbingTime(int depth, int up, int down)
{
	// start cal climbing time
	int time = 0;
	if (depth == 0)
	{
		time = 1;
	}
	else
	{
		bool go = goup;
		while (depth > 0)
		{
			if (go == goup)
			{
				depth -= up;
				go = godown;
				time++;
			}
			else
			{
				depth += down;
				go = goup;
				time++;
			}
		}
	}

	cout << time << endl;
}
int main()
{
    int depth, up, down;
	while (cin >> depth >> up >> down && depth + up + down)
	{
		CCalClimbingTime(depth, up, down);
	}
    return 0;
}

// end 
// ism 

