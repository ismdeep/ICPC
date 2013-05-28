/* 
 * Project Name : F
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 13:14:00 2012 
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

// #define _ISM_DEBUG_ 

string str[1100];
int n;

int iMin (int a, int b)
{
	return (a < b) ? a : b;
}

bool str_cmp(string s,string s1)
{
	char ts[15];
	int len,len1;
	len=s.length();
	len1=s1.length();
	int tlen=min(len,len1);
	for(int i=0;i<tlen;i++)
	    if(s[i]<s1[i])
	    {
		    return true;
	    }
	    else if(s[i]>s1[i])
	    {
		    return false;
	    }
	if(tlen==len)
	{
		int cnt=0;
		for(int i=tlen;i<=len1;i++)
			ts[cnt++]=s1[i];
	return str_cmp(s,ts);
	}
	else
	{
	    int cnt=0;
	    for(int i=tlen;i<=len;i++)
	        ts[cnt++]=s[i];
	    return str_cmp(ts,s1);
	}
}


int main () 
{
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		//
#ifdef _ISM_DEBUG_
		for (int i = 0; i < n; i++)
		{
			cout << str[i] << " ";
		}
		cout << endl;
#endif
		sort (str, str + n, str_cmp);
		for (int i = 0; i < n; i++)
		{
			cout << str[i];
		}
		cout << endl;
		//
		//
		//
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

