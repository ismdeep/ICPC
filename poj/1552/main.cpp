/*
 * Project     : 1552
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 14:31:31 2012 
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

#define MAXN 10000

int data[MAXN];
int top = -1;

bool cmp(int a, int b)
{
	return a < b;
}

void show_data()
{
	for (int i = 0; i <= top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

int main()
{
	int tmp;
	while (cin >> tmp && tmp != -1)
	{
		top = -1;
		top++;
		data[top] = tmp;
		while (cin >> tmp && tmp != 0)
		{
			top++;
			data[top] = tmp;
		}
		// show_data();
		sort(data, data + top + 1, cmp);
		// show_data();
		// 
		int count = 0;
		for (int i = 0; i < top; i++)
		{
			for (int j = i + 1; data[i] * 2 >= data[j] && j <= top; j++)
			{
				if (data[j] == data[i] * 2)
				{
					// cout << " -- " << data[i] << " " << data[j] << endl;
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

