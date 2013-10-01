/* 
 * Project Name : 1141
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:10:43 2013 
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
	string id;
	int score;
	for (int i = 1; i <= 50; i++)
	{
		cin >> id >> score;
		if (score >= 80)
		{
			cout << id << " " << score << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

