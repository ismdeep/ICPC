/*
 * Project     : 1182
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 23:59:42 2012 
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

const bool odd  = true;
const bool even = false;

bool is_odd(longint num)
{
    int count = 0;
    while (num)
    {
        if (num % 2 == 1)
        {
            count++;
        }
        num /= 2;
    }
    if (count % 2 == 1)
    {
        return odd;
    }
    else
    {
        return even;
    }
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		longint num;
        cin >> num;
        if (is_odd(num))
        {
            cout << "odd"  << endl;
        }
        else
        {
            cout << "even" << endl;
        }
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

