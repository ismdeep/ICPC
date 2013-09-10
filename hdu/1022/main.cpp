/*
 * Project     : 1022
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 13:31:01 2012 
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
#include <fstream>
using namespace std;
typedef long long int longint;

class Stack
{
public:
	/* data section */
	char* a;
	int size;
	int index;
	/* procedure section */
	void set_size(int size);
	void init();
	bool is_empty();
	char get_top();
	void pop();
	void push(char num);
	void show_stack();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// debug()
void debug()
{
	cout << "--debug msg--" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: set_size()
void Stack::set_size(int size)
{
	this -> size = size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: is_empty()
bool Stack::is_empty()
{
	return (index == -1) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: init()
void Stack::init()
{
	index = -1;
	a = new char[size*2];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: get_top()
char Stack::get_top()
{
	return a[index];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: pop()
void Stack::pop()
{
	index--;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: push(int num)
void Stack::push(char num)
{
	index++;
	a[index] = num;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack :: show_stack()
void Stack::show_stack()
{
	for (int i = 0; i <= index; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
int main()
{
	const string s_in_op = "in";
	const string s_ou_op = "out";
	int size;
	while (cin >> size)
	{
		string* Operation;
		Operation = new string[size*3];
		int top_op = -1;
		string str_in;
		string str_out;
		int out_index = 0;
		cin >> str_in >> str_out;
		Stack stack;
		stack.set_size(size);
		stack.init();
		for (int i = 0; i < size; i++)
		{
			//stack.show_stack();
			stack.push(str_in[i]);
			top_op++;
			Operation[top_op] = s_in_op;
			while (!stack.is_empty()&& out_index < size && stack.get_top() == str_out[out_index])
			{
				stack.pop();
				out_index++;
				top_op++;
				Operation[top_op] = s_ou_op;
			}
		}
		if (stack.is_empty())
		{
			cout << "Yes." << endl;
			for (int i = 0; i <= top_op; i++)
			{
				cout << Operation[i] << endl;
			}
			cout << "FINISH" << endl;
		}
		else
		{
			cout << "No." << endl;
			cout << "FINISH" << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

