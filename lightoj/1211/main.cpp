/*
 * Project     : 1211
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Aug 30 21:08:36 2012 
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

typedef unsigned long long int longint;

class Cube
{
public:
	int x1, y1, z1;
	int x2, y2, z2;
	int get_volume();
};

int Cube::get_volume()
{
	if (x1 < x2 && y1 < y2 && z1 < z2)
	{
		return (x2 - x1) * (y2 - y1) * (z2 - z1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		int n;
		scanf("%d", &n);
		Cube* cube;
		cube = new Cube[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d", &cube[i].x1, &cube[i].y1, &cube[i].z1, &cube[i].x2, &cube[i].y2, &cube[i].z2);
		}
		Cube intersection;
		int tmp;
		/* max section */
		/*x1*/
		tmp = cube[0].x1;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].x1 > tmp)
			{
				tmp = cube[i].x1;
			}
		}
		intersection.x1 = tmp;
		//
		tmp = cube[0].y1;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].y1 > tmp)
			{
				tmp = cube[i].y1;
			}
		}
		intersection.y1 = tmp;
		//
		tmp = cube[0].z1;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].z1 > tmp)
			{
				tmp = cube[i].z1;
			}
		}
		intersection.z1 = tmp;
		/* min section */
		tmp = cube[0].x2;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].x2 < tmp)
			{
				tmp = cube[i].x2;
			}
		}
		intersection.x2 = tmp;
		//
		tmp = cube[0].y2;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].y2 < tmp)
			{
				tmp = cube[i].y2;
			}
		}
		intersection.y2 = tmp;
		//
		tmp = cube[0].z2;
		for (int i = 1; i < n; i++)
		{
			if (cube[i].z2 < tmp)
			{
				tmp = cube[i].z2;
			}
		}
		intersection.z2 = tmp;
		//
		//
		// cal result;
		cout << intersection.get_volume() << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

