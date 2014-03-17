/* 
 * Project Name : 2A
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Nov 20 10:26:34 2013 
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

char w[105];
int main()
{
	int n;
	while (cin >> n)
	{
		int Sum[1005];
		string Name[1005];
		map<string,int> m;
		string name;
		int sum;
		for (int i = 0; i < n; i++)
		{
			cin >> name >> sum;
			m[name] += sum;
			Sum[i] = m[name];
			Name[i] = name;
		}
		sum = 0;
		for (map<string,int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if (it->second > sum) sum = it->second;
		}
		int i;
		for (i = 0; i < n; i++)
		{
			if (Sum[i] >= sum && m[Name[i]] == sum) break;
		}
		cout << Name[i] << endl;
	}
	return 0;
}

// ismdeep
// xTarget
//

