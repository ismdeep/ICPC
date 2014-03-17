/* 
 * Project Name : 2521
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Nov 29 09:31:35 2013 
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

int cal_divisor (int n)
{
	int cnt = 0;
	int sq = sqrt ((double)n+0.000001);
	for (int i = 1; i <= sq; i++)
	{
		if (0 == n % i)
			cnt++;
	}
	cnt *= 2;
	if (n == sq*sq)
	{
		cnt--;
	}
	return cnt;
}

int main () 
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int max_tag;
		int max_tag_value;
		max_tag = cal_divisor (a);
		max_tag_value = a;
		for (int i = a+1; i <= b; i++)
		{
			int tmp = cal_divisor (i);
			if (tmp > max_tag)
			{
				max_tag = tmp;
				max_tag_value = i;
			}
		}
		cout << max_tag_value << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

