/*
 * Project     : D
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 15:09:34 2012 
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

double ctof(double c)
{
	return 32+c*9.0/5.0;
}

int main()
{
	double c;
	for(c=-100;c<=150;c+=5)
	{
		printf("c=%.0lf->f=%.0lf\n",c,ctof(c));
	}

	return 0;
}


// end 
// iCoding@CodeLab
//

