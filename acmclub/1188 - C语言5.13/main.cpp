/* 
 * Project Name : 1188
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 20:54:45 2013 
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
	int a[4];
	for (int i = 0; i < 4; i ++) cin >> a[i];
	sort (a,a+4);
	for (int i = 0; i < 3; i ++) cout << a[i] << " ";
	cout << a[3] << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

