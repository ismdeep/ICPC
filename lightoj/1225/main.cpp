/*
 * Project     : 1225
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 14:42:04 2012 
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

typedef long long int longint;

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		string s;
		cin >> s;
		bool yes = true;
		for (int i = 0; yes && i <= s.length() - 1; i++)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				yes = false;
			}
		}
		if (yes)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No"  << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

