/* 
 * Project Name : 1010
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Nov 27 10:34:31 2012 
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

#define MAXN 11000

int iData[MAXN];
int n, k;

int main () 
{
	while (scanf ("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &iData[i]);
		}
		sort (iData, iData + n);
		printf ("%d", iData[0]);
		for (int i = 1; i < k; i++)
		{
			printf (" %d", iData[i]);
		}
		printf ("\n");
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

