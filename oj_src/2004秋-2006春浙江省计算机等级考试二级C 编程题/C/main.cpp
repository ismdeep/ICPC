/*
 * Project     : C
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 15:08:53 2012 
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
	double x,res;
	scanf("%lf",&x);
	if(x<0)
		res = fabs(x);
	else if(0<=x && x<2)
		res = sqrt(x+1);
	else if(2<=x && x<4)
		res = pow(x+2,5.0);
	else
		res = 2*x+5;
	printf("%.2lf\n",res);

	return 0;
}


// end 
// iCoding@CodeLab
//

