/*
 * Project     : G
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 15:12:02 2012 
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

#include <stdio.h>

double fact(int n)
{
	static double res = 1.0;
	res *= n;
	return res;
}

int main()
{
	int n,i;
	double sum = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum += 1.0/fact(i);
	}
	printf("sum=%.5lf\n",sum);

	return 0;
}


// end 
// iCoding@CodeLab
//

