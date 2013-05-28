#include <iostream>
#include "Maze.h"
#include "Stack.cpp"
using namespace std;

///////////////////////////////////////////////////////////
Maze::Maze ()
{
	this->n = 0;
	this->m = 0;
	for (int i = 0; i < MAX_MAXE_SIZE; i++)
	{
		for (int j = 0; j < MAX_MAXE_SIZE; j++)
		{
			this->iMap[i][j].set_point (i, j);
		}
	}
}


///////////////////////////////////////////////////////////
void Maze::set_all_block ()
{
	for (int i = 0; i < MAX_MAXE_SIZE + 2; i++)
	{
		for (int j = 0; j < MAX_MAXE_SIZE + 2; j++)
		{
			this->iMap[i][j].set_value (ch_block);
		}
	}
}

///////////////////////////////////////////////////////////
void Maze::input_iMap ()
{
	cin >> n >> m;
	if (n > MAX_MAXE_SIZE || m > MAX_MAXE_SIZE)
	{
		cout << "n and m must be small than "
			 << MAX_MAXE_SIZE 
			 << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		string str_line;
		cin >> str_line;
		cout << str_line << endl;
		for (int j = 1; j <= m; j++)
		{
			this->iMap[i][j].set_value (str_line[j-1]);
		}
	}
}

///////////////////////////////////////////////////////////
// This is the kernel of the program
// I'd love to introduce it to you.
// It's a little hard to say about
// I will put a Point into the stack
void Maze::search_route ()
{
}

