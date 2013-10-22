/* 
 * Project Name : 1148
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Wed Oct  2 23:10:25 2013 
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
	int n;
	cin >> n;
	if (n % 3 == 0 && n % 5 == 0)
	{
		cout << "can" << endl;
	}
	else
	{
		cout << "cannot" << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

