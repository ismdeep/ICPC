/* 
 * Project Name : 1008
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Mon Dec 17 10:09:16 2012 
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

#define MAXN 110

int iMap[MAXN][MAXN];
int nSize;

void input_iMap ()
{
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cin >> iMap[i][j];
		}
	}
}

int cal_sum_1 ()
{
	int sum = 0;
	for (int i = 0; i < nSize; i++)
	{
		sum += iMap[i][i];
	}
	return sum;
}


int cal_sum_2 ()
{
	int sum = 0;
	for (int i = 0; i < nSize; i++)
	{
		sum += iMap[i][nSize-i-1];
	}
	return sum;
}

int main () 
{
	while (cin >> nSize)
	{
		input_iMap ();
		cout << cal_sum_1 () << endl
			 << cal_sum_2 () << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

