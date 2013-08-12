/*
 * Project     : 1212
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 12:46:22 2012 
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

typedef long long int longint;

#define MAXN 10010

class DoubleEndQueue
{
public:
	int a[MAXN];
	int size;
	int left_index;
	int right_index;
	void set_size();
	void init();
	bool is_empty();
	bool is_full();
	void push_left(int num);
	void push_right(int num);
	void pop_left();
	void pop_right();
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: set_size()
void DoubleEndQueue::set_size()
{
	cin >> size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: init()
void DoubleEndQueue::init()
{
	left_index  = MAXN / 2;
	right_index = MAXN / 2 - 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: is_empty()
bool DoubleEndQueue::is_empty()
{
	return (left_index > right_index) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: is_full()
bool DoubleEndQueue::is_full()
{
	return ((right_index - left_index + 1) == size) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: push_left(int num)
void DoubleEndQueue::push_left(int num)
{
	if (is_full())
	{
		// DoubleEndQueue is full ,, so ... can't push any thing
		cout << "The queue is full" << endl;
	}
	else
	{
		left_index--;
		a[left_index] = num;
		// Guten ,, 
		cout << "Pushed in left: " << num << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: push_right(int num)
void DoubleEndQueue::push_right(int num)
{
	if (is_full())
	{
		// DoubleEndQueue is full ,, so ... can't push any thing
		cout << "The queue is full" << endl;
	}
	else
	{
		right_index++;
		a[right_index] = num;
		// Guten ,,
		cout << "Pushed in right: " << num << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: pop_left()
void DoubleEndQueue::pop_left()
{
	if (is_empty())
	{
		// DoubleEndQueue is empty ,, so ... can't get any thing
		cout << "The queue is empty" << endl;
	}
	else
	{
		// Guten ,,
		cout << "Popped from left: " << a[left_index] << endl;
		left_index++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DoubleEndQueue :: pop_right()
void DoubleEndQueue::pop_right()
{
	if (is_empty())
	{
		// DoubleEndQueue is empty ,, so ... can't get any thing
		cout << "The queue is empty" << endl;
	}
	else
	{
		// Guten ,,
		cout << "Popped from right: " << a[right_index] << endl;
		right_index--;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ":" << endl;
		DoubleEndQueue de_queue;
		de_queue.init();
		de_queue.set_size();
		int m;
		cin >> m;
		while (m--)
		{
			string instruc;
			cin >> instruc;
			if (instruc == "pushLeft")
			{
				int num;
				cin >> num;
				de_queue.push_left(num);
			}
			if (instruc == "pushRight")
			{
				int num;
				cin >> num;
				de_queue.push_right(num);
			}
			if (instruc == "popLeft")
			{
				de_queue.pop_left();
			}
			if (instruc == "popRight")
			{
				de_queue.pop_right();
			}
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

