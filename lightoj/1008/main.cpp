/*
 * Project     : 1008
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Aug 28 22:17:41 2012 
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
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		longint s_num;
        cin >> s_num;
        longint index = sqrt((double)s_num);
        if (index * index == s_num)
        {
            if (index % 2 == 0)
            {
                cout << index << " 1" << endl;
            }
            else
            {
                cout << "1 " << index << endl;
            }
        }
        else
        {
            index++;
            if (index % 2 == 0)
            {
                longint go_back = (index * index) - s_num;
                longint x, y;
                x = index;
                y = 1;
                y += go_back;
                if (y > x)
                {
                    longint tmp = y - x;
                    y = x;
                    x = y - tmp;;
                }
                cout << x << " " << y << endl;
            }
            else
            {
                longint go_back = (index * index) - s_num;
                longint x, y;
                x = 1;
                y = index;
                x += go_back;
                if (x > y)
                {
                    longint tmp = x - y;
                    x = y;
                    y = x - tmp;
                }
                cout << x << " " << y << endl;
            }
        }
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

