#include <iostream>
using namespace std;

#define INF 0x3fffffff

#define MAXN 44000

int nSize;

//---- make : src -> des ----//
//---- class Node ----//
class Node
{
public:
	int bin[20];
	int hash ();
};

int Node::hash ()
{
	int iTmp;
	iTmp = 0;
	for (int i = 1; i <= nSize; i++)
	{
		iTmp *= 2;
		iTmp += bin[i];
	}
	return iTmp;
}
//---- class end ----//

Node node_src;
Node node_des;

Node link[MAXN];
	Node tmp_link[MAXN];
int left_index;
int right_index;

bool mark[MAXN];

int search_level;

void init_mark ()
{
	for (int i = 0; i < MAXN; i++)
	{
		mark[i]      = true;
	}
	mark[node_src.hash()] = false;
	//
}

void iBFS (int level)
{
	if (level > 15 || search_level > 0)
	{
		return;
	}
	for (int i = left_index; i <= right_index; i++)
	{
		mark[link[i].hash()] = false;
	}
	int index_tmp_left;
	int index_tmp_right;
	index_tmp_left = 0;
	index_tmp_right = -1;
	for (int i = left_index; i <= right_index; i++)
	{
		Node node_tmp;
		node_tmp = link[i];
		for (int j = 1; j <= nSize; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				node_tmp.bin[j+k] = 1 - node_tmp.bin[j+k];
			}
			if (mark[node_tmp.hash()])
			{
				index_tmp_right++;
				tmp_link[index_tmp_right] = node_tmp;
			}
			for (int k = -1; k <= 1; k++)
			{
				node_tmp.bin[j+k] = 1 - node_tmp.bin[j+k];
			}
		}
	}
	for (int i = index_tmp_left; i <= index_tmp_right; i++)
	{
		if (tmp_link[i].hash() == node_des.hash())
		{
			if (search_level < 0)
			{
				search_level = level;
			}
		}
	}
	for (int i = index_tmp_left; i <= index_tmp_right; i++)
	{
		link[i] = tmp_link[i];
		mark[link[i].hash()] = false;
	}
	left_index  = index_tmp_left;
	right_index = index_tmp_right;
}

void input_src_des ()
{
		for (int i = 1; i <= nSize; i++)
		{
			cin >> node_src.bin[i];
		}
		for (int i = 1; i <= nSize; i++)
		{
			cin >> node_des.bin[i];
		}
}

int main ()
{
	while (cin >> nSize)
	{
		search_level = -1;
		//
		init_mark ();
		input_src_des ();
		//
		left_index  = 0;
		right_index = 0;
		link[0] = node_src;
		//
		iBFS(1);
		cout << search_level << endl;
	}
	return 0;
}


