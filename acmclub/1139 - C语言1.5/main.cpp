/* 
 * Project Name : 1139
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:00:44 2013 
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

int main () 
{ 
	int a, b, c;
	while (scanf ("%d,%d,%d", &a, &b, &c) != EOF)
	{
		int max = a;
		if (max < b) {max = b;}
		if (max < c) {max = c;}
		printf ("max=%d\n", max);
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

