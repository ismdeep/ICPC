#include <iostream>
#include "Stack.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// constructor function of Stack
Stack::Stack ()
{
	this -> size   = DEFAULT_STACK_SIZE;
	this -> bottom = 0;
	this -> top    = this -> bottom;
	this -> data   = new char[size+1];
}

/////////////////////////////////////////////////////////////////////
// ~Stack
Stack::~Stack ()
{
	delete[] this -> data;
	this -> bottom = 0;
	this -> top    = 0;
	this -> size   = 0;
}
/////////////////////////////////////////////////////////////////////
// get top element from Stack
char Stack::get_top ()
{
	return this -> data [this -> top];
}
/////////////////////////////////////////////////////////////////////
// push an element into Stack
void Stack::push (char e)
{
	this -> top ++;
	this -> data [this -> top] = e;
}
/////////////////////////////////////////////////////////////////////
// pop an element from Stack
void Stack::pop ()
{
	this -> top--;
}
/////////////////////////////////////////////////////////////////////
// judge if a Stack is empty
bool Stack::is_empty ()
{
	return (this -> top <= this -> bottom);
}
/////////////////////////////////////////////////////////////////////
// judge if a Stack is full
bool Stack::is_full ()
{
	return (this -> top >= this -> size);
}
/////////////////////////////////////////////////////////////////////
// show stack elements from bottom to top
void Stack::show_from_bottom ()
{
	for (int i = this->bottom+1; i <= this->top; i++)
	{
		cout << this->data[i];
	}
	cout << endl;
}
// end 
// iCoding
// 
