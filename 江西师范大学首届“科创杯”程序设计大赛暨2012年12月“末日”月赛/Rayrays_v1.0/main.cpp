#include <iostream>
using namespace std;

#define INF 0x3fffffff

#define MAXN 44000

//---- make : src -> des ----//
int src[20];
int des[20];

bool mark[MAXN];
int min_level[MAXN];


int nSize;
int search_level;

void show_src ()
{
	for (int i = 1; i <= nSize; i++)
	{
		cout << src[i];
	}
	cout << endl;
}

void init_mark ()
{
	for (int i = 0; i < MAXN; i++)
	{
		mark[i] = true;
		min_level[i] = INF;
	}
	int src_hash ();
	mark[src_hash()] = false;
	//
}

int src_hash ()
{
	int iTmp = 0;
	for (int i = 1; i <= nSize; i++)
	{
		iTmp *= 2;
		iTmp += src[i];
	}
	return iTmp;
}


void iDFS (int level)
{
	// show_src ();
	if (level < 15)
	{
		bool iFlag = true;
		for (int i = 1; iFlag && i <= nSize; i++)
		{
			if (src[i] != des[i])
			{
				iFlag = false;
			}
		}
		if (iFlag)
		{
			if (search_level > level)
			{
				search_level = level;
			}
		}
		else
		{
			///////////////////////////////////////////////////////////
			if (mark[src_hash()])
			{
				mark[src_hash()] = false;
				//---- kernel ----//
				for (int index = 1; index <= nSize; index++)
				{
					for (int i = -1; i <= 1; i++)
					{
						src[index + i] = 1 - src[index + i];
					}
					iDFS (level + 1);
					for (int i = -1; i <= 1; i++)
					{
						src[index + i] = 1 - src[index + i];
					}
				}
				mark[src_hash()] = true;
			}
			///////////////////////////////////////////////////////////
		}
	}
}

void input_src_des ()
{
		for (int i = 1; i <= nSize; i++)
		{
			cin >> src[i];
		}
		for (int i = 1; i <= nSize; i++)
		{
			cin >> des[i];
		}
}

int main ()
{
	while (cin >> nSize)
	{
		search_level = INF;
		//
		init_mark ();
		input_src_des ();
		//
		iDFS (0);
		cout << search_level << endl;
	}
	return 0;
}


