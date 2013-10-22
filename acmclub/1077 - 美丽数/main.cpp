/* 
 * Project Name : 1077
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct 15 20:39:58 2013 
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

#define MAXN 110000

int _shit_[MAXN];

void make_shit_map ()
{
	int value = 1;
	int shit_index = 0;
	while (shit_index < MAXN-10)
	{
		while (value % 3 != 0 && value % 5 != 0)
		{
			value++;
		}
		shit_index++;
		_shit_[shit_index] = value;
		value++;
	}
}

int main () 
{
	make_shit_map ();
	int n;
	while (scanf ("%d", &n) != EOF)
	{
		//cout << _shit_[n] << endl;
		printf ("%d\n", _shit_[n]);
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

