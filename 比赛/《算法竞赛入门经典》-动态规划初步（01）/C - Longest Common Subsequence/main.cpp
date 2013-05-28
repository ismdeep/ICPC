/* 
 * Project Name : C
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Oct 27 10:03:27 2012 
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

int dp_map [1100][1100];

char str_a[1100];
char str_b[1100];
int a_length;
int b_length;

int iMax (int a, int b)
{
	return (a > b) ? a : b;
}

int main () 
{
	while (gets (str_a) != NULL)
	{
		gets (str_b);
		memset (dp_map, 0, sizeof(dp_map));
		a_length = strlen (str_a);
		b_length = strlen (str_b);
		if (a_length == 0 || b_length == 0)
		{
			break;
		}
		for (int a_index = 0; a_index < a_length; a_index++)
		{
			for (int b_index = 0; b_index < b_length; b_index++)
			{
				int i, j;
				i = a_index + 1;
				j = b_index + 1;
				if (str_a[a_index] == str_b[b_index])
				{
					dp_map[i][j] = dp_map[i-1][j-1] + 1;
				}
				else
				{
					dp_map[i][j] = iMax (dp_map[i-1][j], dp_map[i][j-1]);
				}
			}
		}
		cout << dp_map[a_length][b_length] << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

