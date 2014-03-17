/* 
 * Project Name : 11364
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 16:46:07 2013 
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int _min_;
		int _max_;
		int _tmp_;
		cin >> n;
		cin >> _min_;
		_max_ = _min_;
		n--;
		while (n--)
		{
			cin >> _tmp_;
			if (_tmp_ < _min_)
			{
				_min_ = _tmp_;
			}
			if (_tmp_ > _max_)
			{
				_max_ = _tmp_;
			}
		}
		_max_ -= _min_;
		cout << _max_ * 2 << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

