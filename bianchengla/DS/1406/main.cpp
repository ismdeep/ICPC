/*
 * Project     : 1406
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 20:40:22 2012 
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
using namespace std;

typedef unsigned long long int longint;

int main()
{
	int iT;
	scanf("%d", &iT);
	string str;
	getline(cin, str);
	while (iT--)
	{
		// input data
		string line;
		int data[10000];
		getline(cin, line);
		istringstream str_cin(line);
		//
		int tmp;
		int top = -1;
		while (str_cin >> tmp)
		{
			top++;
			data[top] = tmp;
		}
		//
		//
		// process
		int ans = 0;
		for (int i = 1; i <= top; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if (data[i] < data[j])
				{
					// cout << data[i] << " " << data[j] << endl;
					ans++;
				}
			}
		}
		//
		//
		// output result
		cout << ans << endl;
		//
		//
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

