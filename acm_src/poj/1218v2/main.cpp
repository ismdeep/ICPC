/*
 * Project     : 1218v2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep 15 10:15:39 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

//#define _DEBUG_

#define MAXN 1100

#define OPEN true
#define CLOSED false

char iStatus[2] = {'0', '1'};

bool iDoor[MAXN];
int n;

void iShowDoor()
{
	for (int i = 1; i <= n; i++)
	{
		cout << iStatus[iDoor[i]];
	}
	cout << endl;
}

void iInitDoor()
{
	for (int index = 1; index <= n; index++)
	{
		iDoor[index] = CLOSED;
	}
}

void iChangeStatus(int index)
{
	for (int j = index; j <= n; j += index)
	{
		iDoor[j] = !iDoor[j];
	}
}

int iCountOpenDoor()
{
	int count = 0;
	for (int index = 1; index <= n; index++)
	{
		if (iDoor[index] == OPEN)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		cin >> n;
		iInitDoor();
		for (int i = 1; i <= n; i++)
		{
			iChangeStatus(i);
#ifdef _DEBUG_
			iShowDoor();
#endif
			//
		}
		cout << iCountOpenDoor() << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

