#include <iostream>
using namespace std;

#ifndef DEFAULT_STACK_SIZE
#define DEFAULT_STACK_SIZE 1000
#endif

class Stack
{
	private:
		char* data;
		int bottom;
		int top;
		int size;
	public:
		Stack ();
		~Stack ();
		char get_top ();
		void push (char e);
		void pop ();
		bool is_empty ();
		bool is_full ();
};


