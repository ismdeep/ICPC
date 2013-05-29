/*
 * Project     : 1207
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 14:43:47 2012 
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

#define MAXN 42440000

int length[MAXN];

int cal_length(int num)
{
	// cout << num;
	if (num == 1 || length[num] != 0)
	{
		return length[num];
	}
	else
	{
		/*
		if (num % 2 == 1)
		{
			length[num] = cal_length(num * 3 + 1) + 1;
			return length[num];
		}
		else
		{
			length[num] = cal_length(num / 2) + 1;
			return length[num];
		}
		*/
		/*****************************************************************/
		/* version 2*/
		int count = 0;
		bool stop = false;
		while (num != 1 && !stop)
		{
			// cout << "!" << num << " ";
			if (length[num] != 0 || num == 1)
			{
				count += length[num];
				stop = true;
			}
			else
			{
				if (num % 2 == 1)
				{
					num = 3 * num + 1;
				}
				else
				{
					num = num / 2;
				}
				count++;
			}
		}
		length[num] = count;
		// cout << "--" << endl;
		return count;
	}
}

void make_length_map()
{
	/* init for length[] */
	memset(length, 0, sizeof(length));
	for (int i = 2; i < 11000; i++)
	{
		if (length[i] == 0)
		{
			length[i] = cal_length(i);
		}
	}
}

int iMax(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	make_length_map();
	int a, b;
	while (cin >> a >> b)
	{
		int max_length = 0;
		for (int index = a; index <= b; index++)
		{
			int tmp_length;
			tmp_length = length[index];
			max_length = iMax(tmp_length, max_length);
		}
		cout << a << " " << b << " " << max_length << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

