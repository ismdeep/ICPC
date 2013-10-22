/* 
 * Project Name : 1140
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:03:43 2013 
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

typedef long long int LL;

LL fact (LL n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * fact (n-1);
	}
}

int main () 
{ 
	cout << fact (5) << endl;
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

