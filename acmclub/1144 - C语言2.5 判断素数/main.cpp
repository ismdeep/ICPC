/* 
 * Project Name : 1144
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:22:52 2013 
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

bool is_prime (int n)
{
	bool isok = true;
	int tmp = sqrt((double)n + (double)0.55);
	for (int i = 2; isok && i <= tmp; i++)
	{
		if (0 == n % i)
		{
			isok = false;
		}
	}
	return isok;
}

int main () 
{ 
	int n;
	while (cin >>n)
	{
		if (is_prime(n))
		{
			cout << "prime" << endl;
		}
		else
		{
			cout << "not prime" << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

