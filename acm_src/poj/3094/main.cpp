/*
 * Project     : 3094
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 23 20:08:30 2012 
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
using namespace std;

#define MAXN 300

char s[MAXN];
int top;

int main()
{
	char ch;
	while (cin.get(ch) && ch != '#')
	{
		top = 1;
		s[top] = ch;
		while (cin.get(ch) && ch != '\n')
		{
			top++;
			s[top] = ch;
		}
		int sum = 0;
		for (int i = 1; i <= top; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				sum += (i * (s[i] - 'A' + 1));
			}
		}
		cout << sum << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

