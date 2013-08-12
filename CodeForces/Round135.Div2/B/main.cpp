/*
 * Project     : B
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Aug 28 00:29:23 2012 
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
using namespace std;


typedef unsigned long long int longint;

void debug()
{
	cout << "--debug msg--" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// data section
longint nines[21];

class NumberSelector
{
public:
	longint p;
	int p_length;
	longint d;
	longint min;
	longint max;
	longint max_guten;
	bool found;
	/* procedure */
	void set_value(int p, int d);
	void set_p_length();
	bool is_in_number_selector(longint num);
	void init();
	void make_max_guten();
	bool try_length(int length);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: set_value(int p, int d)
void NumberSelector::set_value(int p, int d)
{
	this -> p = p;
	this -> d = d;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: set_p_length()
void NumberSelector::set_p_length()
{
	longint tmp;
	tmp = p;
	p_length = 0;
	while (tmp)
	{
		p_length++;
		tmp /= 10;
	}
	if (p_length == 0)
	{
		p_length = 1;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: is_in_number_selector()
bool NumberSelector::is_in_number_selector(longint num)
{
	return (num >= min && num <= max) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: init()
void NumberSelector::init()
{
	max = p;
	min = p - d;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: make_max_guten()
void NumberSelector::make_max_guten()
{
	for(int length = p_length - 1; !found && length >= 1; length++)
	{
		if (try_length(length))
		{
			found = true;
		}
	}
	if (found)
	{
		cout << max_guten << endl;
	}
	else
	{
		cout << max << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NumberSelector :: try_length(int length)
bool NumberSelector::try_length(int length)
{
	bool yes = false;
	longint left;
	longint right;
	left = 0;
	right = nines[p_length - length];
	longint mid_num;
	longint mid_num1;
	while (left <= right)
	{
		// longint mid_num;
		mid_num = ((left + right) / 2) * (nines[length]+1) + nines[length];
		mid_num1 = ((left + right) / 2 + 1) * (nines[length]+1) + nines[length];
		if (mid_num >= max)
		{
			right = mid_num;
		}
		else if (mid_num1 <= min)
		{
			left  = mid_num1;
		}
		else
		{
			left  = mid_num1;
		}
		cout << mid_num << " " << mid_num1 << endl;
	}
	if (is_in_number_selector(mid_num))
	{
		max_guten = mid_num;
		return true;
	}
	else
	{
		return false;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// make nines
void make_nines()
{
	nines[0] = 0;
	nines[1] = 9;
	for (int i = 2; i < 21; i++)
	{
		nines[i] = nines[i-1] * 10 + 9;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	make_nines();
	longint tmp_p, tmp_d;
	while (cin >> tmp_p >> tmp_d)
	{
		NumberSelector number_selector;
		number_selector.set_value(tmp_p, tmp_d);
		number_selector.set_p_length();
		number_selector.init();
		number_selector.make_max_guten();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

