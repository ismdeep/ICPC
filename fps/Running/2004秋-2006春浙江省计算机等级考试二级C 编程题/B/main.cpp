/*
 * Project     : B
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 15:08:27 2012 
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

double fact(int n)
{
	static double res = 1.0;
	res *= n;

	return res;
}

double mypow(double x,int n)
{
	return pow(x,(double)n);
}

int main()
{
	double x,sum=0;
	int n;
	int i;
	scanf("%lf %d",&x,&n);
	for(i=1;i<=n;i++)
	{
		if(i%2 == 0)
			sum -= mypow(x,i)/fact(i);
		else
			sum += mypow(x,i)/fact(i);
	}
	printf("%.4lf\n",sum);

	return 0;
}



// end 
// iCoding@CodeLab
//

