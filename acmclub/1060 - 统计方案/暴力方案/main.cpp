/* 
 * Project Name : 1060
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 15:42:11 2013 
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

#define MAXN 22

const int LEFT = -1;
const int RIGH =  1;
const int UP   =  2;

const int dir[3] = {LEFT, RIGH, UP};

int path[MAXN];
int n;
int path_count;

void init ()
{
	path[0] = UP;
	path_count = 0;
}

void search (int dep)
{
	if (dep >= n)
	{
		path_count++;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (path[dep-1] + dir[i] != 0)
			{
				path[dep] = dir[i];
				search (dep+1);
			}
		}
	}
}

int main () 
{
	//while (cin >> n)
	for (n = 2; n <= 22; n++)
	{
		init();
		search (1);
		//cout << path_count << endl << endl;
		cout << path_count <<",";
	}
	cout << endl << endl;
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

