/* 
 * Project Name : 1189
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Oct 28 12:07:48 2013 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

const double eps = 1e-8;

typedef struct Point
{
	double x,y;
}Point;

void set_point_value (double x, double y, Point& p)
{
	p.x = x;
	p.y = y;
}


//(2，2)，(-2，2)，(2，-2)，(-2，-2)

double dis (Point p1, Point p2)
{
	return (double)sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int main () 
{
	Point p[4];
	set_point_value (2,2,p[0]);
	set_point_value (-2,2,p[1]);
	set_point_value (2,-2,p[2]);
	set_point_value (-2,-2,p[3]);
	double a, b;
	while (scanf ("%lf%lf", &a, &b) != EOF)
	{
		Point pp;
		set_point_value (a,b,pp);
		bool found = false;
		for (int i = 0; !found && i < 4; i++)
			if (dis(pp,p[i]) + eps < (double)1 || dis(pp,p[i]) - eps < (double)1)
			{
				printf ("10.00\n");
				found = true;
			}
		if (!found)
		{
			printf ("0.00\n");
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

