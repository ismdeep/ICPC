/*
 * Project     : F
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Oct  5 19:45:24 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

#define MAX_SIZE 5500

///////////////////////////////////////////////////////////
class Number
{
	private:
		int data[MAX_SIZE];
	public:
		Number ();
		Number (string str_msg);
		void set_zero ();
		friend Number operator + (Number a, Number b);
		void manage ();
		int get_data (int index);
		void set_data (int index, int value);
		void show_value ();
};

Number::Number ()
{
	memset (this->data, 0, sizeof (this->data));
}

Number::Number (string str_msg)
{
	memset (this->data, 0, sizeof (this->data));
	int top = str_msg.length() - 1;
	for (int i = 0; i <= top; i++)
	{
		this->data[top-i] = (str_msg[i] - '0');
	}
}

void Number::set_zero ()
{
	memset (this->data, 0, sizeof (this->data));
}

Number operator + (Number a, Number b)
{
	Number sum;
	sum.set_zero ();
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int tmp = 0;
		tmp += a.get_data (i);
		tmp += b.get_data (i);
		sum.set_data (i, tmp);
	}
	sum.manage ();
	return sum;
}

void Number::manage ()
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		this->data[i+1] += (this->data[i] / 10);
		this->data[i]   %= 10;
	}
}

int Number::get_data (int index)
{
	return this->data[index];
}

void Number::set_data (int index, int value)
{
	this->data[index] = value;
}

void Number::show_value ()
{
	int top = MAX_SIZE - 1;
	while (this->data[top] == 0)
	{
		top--;
	}
	for (int i = top; i >= 0; i--)
	{
		cout << this->data[i];
	}
}

///////////////////////////////////////////////////////////
int main()
{
	int t;
	cin >> t;
	for (int case_index = 1; case_index <= t; case_index++)
	{
		if (case_index != 1)
		{
			cout << endl;
		}
		cout << "Case " << case_index << ":" << endl;
		string str_a;
		string str_b;
		cin >> str_a >> str_b;
		cout << str_a << " + " << str_b << " = ";
		Number num_a(str_a);
		Number num_b(str_b);
		Number num_sum;
		num_sum = num_a + num_b;
		num_sum.show_value ();
		cout << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

