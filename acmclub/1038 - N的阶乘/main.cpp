/* 
 * Project Name : 1038
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Nov 27 10:39:05 2012 
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

#define _ARR_SIZE_ 4000

#define MAXN 1100

class Number
{
	public:
		int iData[_ARR_SIZE_];
		int iTop;
		//
		Number ();
		void mul_num (Number iNum, int num_value);
		void show_value ();
};

Number::Number ()
{
	memset (this->iData, 0, sizeof(this->iData));
	iTop = -1;
}

void Number::mul_num (Number iNum, int num_value)
{
	for (int i = 0; i <= iNum.iTop; i++)
	{
		this->iData[i] = iNum.iData[i] * num_value;
	}
	this->iTop = iNum.iTop + 10;
	for (int i = 0; i < this->iTop; i++)
	{
		this->iData[i+1] += (this->iData[i] / 10);
		this->iData[i]   %= 10;
	}
	while (0 == this->iData[iTop])
	{
		this->iTop--;
	}
}

void Number::show_value ()
{
	for (int i = this->iTop; i >= 0; i--)
	{
		printf ("%d", this->iData[i]);
	}
	printf ("\n");
}

Number number[MAXN+1];

void init_number ()
{
	number[0].iData[0] = 1;
	number[0].iTop     = 0;
	for (int i = 1; i <= MAXN; i++)
	{
		number[i].mul_num (number[i-1], i);
	}
}

int main ()
{
	init_number ();
	int n;
	while (cin >> n)
	{
		number[n].show_value ();
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
//

