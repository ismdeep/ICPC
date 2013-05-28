/*
 * Project     : A
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Oct 18 13:54:00 2012 
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

typedef long long int longint;

int main()
{
    longint n, m, a;
    while (cin >> n >> m >> a)
    {
	longint w, d;
	w = n / a;
	d = m / a;
	if (n % a != 0)
	{
	    w++;
	}
	if (m % a != 0)
	{
	    d++;
	}
	longint sum = w * d;
	cout << sum << endl;
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

