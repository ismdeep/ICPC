/*
 * Project     : 1004
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Sep 13 20:34:33 2012 
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

#define MONTH_COUNT 12

int main()
{
	float sum = 0.0;
	float tmp;
	for (int i = 0; i < MONTH_COUNT; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	sum /= (float)MONTH_COUNT;
	printf("$%.2f\n", sum);
	return 0;
}

// end 
// iCoding@CodeLab
//

