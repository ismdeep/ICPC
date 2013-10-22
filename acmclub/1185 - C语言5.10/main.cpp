/* 
 * Project Name : 1185
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Oct 11 09:55:56 2013 
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

char grade[101];

void init_grade ()
{
	for (int i = 0; i <= 59; i++)grade[i] = 'E';
	for (int i = 60; i <= 69; i++)grade[i] = 'D';
	for (int i = 70; i <= 79; i++)grade[i] = 'C';
	for (int i = 80; i <= 89; i++)grade[i] = 'B';
	for (int i = 90; i <= 100; i++)grade[i] = 'A';
}

int main () 
{
	init_grade ();
	int score;
	while (cin >> score)
	{
		cout << grade[score] << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

