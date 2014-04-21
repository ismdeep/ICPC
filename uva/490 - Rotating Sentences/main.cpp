/* 
 * Project Name : 490
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Apr 21 14:01:04 2014 
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
#define MAXN 256

int main () 
{
	string str[MAXN];
	char out_map[MAXN][MAXN];
	int index = 0;
	int max_length = 0;
	while (getline(cin,str[index]))
	{
		if (max_length < str[index].length())
		{
			max_length = str[index].length();
			cout << max_length << endl;
		}
		index++;
	}
	// ----- 
	index--;
	index--;
	// ---- init out_map[][]
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			out_map[i][j] = ' ';
		}
	}
	// ---- set value
	for (int s_index = 0; s_index <= index; s_index++)
	{
		for (int j = 0; j < str[s_index].length(); j++)
		{
			out_map[j][index - s_index] = str[s_index][j];
		}
	}
	// ---- output for result
	for (int i = 0; i < max_length; i++)
	{
		for (int j = 0; j <= index; j++)
		{
			cout << out_map[i][j];
		}
		cout << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

