/* 
 * Project Name : 1004
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sun Nov 18 22:43:53 2012 
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

#define _NUMBER_DATA_SIZE_ 1100

class Number
{
	public:
		int data[_NUMBER_DATA_SIZE_];
		Number ();
		void manage_data ();
		void show_value ();
		void set_value_by_int (int num);
		friend Number operator + (Number a, Number b);
};


Number::Number ()
{
	memset (this->data, 0, sizeof(this->data));
}

void Number::set_value_by_int (int num)
{
	data[0] = num;
}

void Number::manage_data ()
{
	for (int i = 0; i < _NUMBER_DATA_SIZE_ - 1; i++)
	{
		this->data[i+1] += (this->data[i] / 10);
		this->data[i]   %= 10;
	}
}

void Number::show_value ()
{
	int iTop = _NUMBER_DATA_SIZE_ - 1;
	while (0 == this->data[iTop] && iTop >= 0)
	{
		iTop--;
	}
	if (iTop < 0)
	{
		iTop = 0;
	}
	for (int i = iTop; i >= 0; i--)
	{
		cout << this->data[i];
	}
	cout << endl;
}

Number operator + (Number a, Number b)
{
	Number sum;
	for (int i = 0; i < _NUMBER_DATA_SIZE_; i++)
	{
		sum.data[i] = a.data[i] + b.data[i];
	}
	sum.manage_data ();
	return sum;
}



Number number[1100];


int main () 
{
	number[1].set_value_by_int (1);
	number[2].set_value_by_int (1);
	for (int i = 3; i < 1100; i++)
	{
		number[i] = number[i-1] + number[i-2];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int iIndex;
		cin >> iIndex;
		number[iIndex].show_value ();
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

