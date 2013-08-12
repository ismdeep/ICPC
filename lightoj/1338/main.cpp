//
//
// Project Name : 1338 - Hidden Secret!
// File    Name : main.cpp
// Author       : iCoding
// Date  & Time : 2012-08-18 13:57
//
//

#include <iostream>
using namespace std;

#ifndef MAXN
#define MAXN 1000
#endif

char a[MAXN];
char b[MAXN];

int a_top;
int b_top;

const char BLOCK = '\0';

/*****************************************************************************/

void iShowArray()
{
	for (int i = 0; i <= a_top; i++)
	{
		cout << a[i];
	}
	cout << endl;
	for (int i = 0; i <= b_top; i++)
	{
		cout << b[i];
	}
	cout << endl;
}

void iInitArray()
{
	for (int i = 0; i < MAXN; i++)
	{
		a[i] = BLOCK;
		b[i] = BLOCK;
	}
	//
	//
	a_top = -1;
	b_top = -1;
}

void iSetArray()
{
	char ch;
	while (cin.get(ch) && ch != '\n')
	{
		if (ch >= 'a' && ch <= 'z')
		{
			a_top++;
			a[a_top] = ch;
		}
		if (ch >= 'A' && ch <= 'Z')
		{
			a_top++;
			a[a_top] = (ch + 32);
		}
	}
	//
	//
	while (cin.get(ch) && ch != '\n')
	{
		if (ch >= 'a' && ch <= 'z')
		{
			b_top++;
			b[b_top] = ch;
		}
		if (ch >= 'A' && ch <= 'Z')
		{
			b_top++;
			b[b_top] = (ch + 32);
		}
	}
}

void iClearArray()
{
	for (int i = 0; i <= a_top; i++)
	{
		bool found = false;
		for (int j = 0; !found && j <= b_top; j++)
		{
			if (a[i] == b[j])
			{
				a[i] = BLOCK;
				b[j] = BLOCK;
				found = true;
			}
		}
	}
}

void iGetAnswer()
{
	bool flag = true;
	for (int i = 0; flag && i < MAXN; i++)
	{
		if (a[i] != '\0' || b[i] != '\0')
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No"  << endl;
	}
}

void iShowHeadMsg(int iCaseID)
{
	cout << "Case " << iCaseID << ": ";
}

/*****************************************************************************/

int main()
{
	int iT;
	cin >> iT;
	cin.get();
	for (int iCaseID = 1; iCaseID <= iT; iCaseID++)
	{
		iShowHeadMsg(iCaseID);
		iInitArray();
		iSetArray();
		//iShowArray();
		iClearArray();
		//iShowArray();
		iGetAnswer();
	}
	return 0;
}

// end 
//
// iCoding@CodeLab
//

