#include <iostream>
using namespace std;

//---- Date Section.
#define MAX_SIZE 100000
int xor_index[17];

class Node
{
public:
	//---- data
	int   value;
	int   way;
	Node* p_pre;
	//---- functions
	Node ();
};

Node** run_map; //---- run program map
int run_map_index[MAX_SIZE];
bool used[MAX_SIZE];


string src_str[4];
int src_value;










//---- Functions.
void InitXorIndex ()
{
	xor_index[ 1] = 63624;
	xor_index[ 2] = 62532;
	xor_index[ 3] = 61986;
	xor_index[ 4] = 61713;
	xor_index[ 5] = 36744;
	xor_index[ 6] = 20292;
	xor_index[ 7] = 12066;
	xor_index[ 8] = 7953 ;
	xor_index[ 9] = 35064;
	xor_index[10] = 17652;
	xor_index[11] = 8946 ;
	xor_index[12] = 4593 ;
	xor_index[13] = 34959;
	xor_index[14] = 17487;
	xor_index[15] = 8751 ;
	xor_index[16] = 4383 ;
}

Node::Node ()
{
	this->p_pre = NULL;
	this->value = 0;
}

void InitRunMapIndex ()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		run_map_index[i] = -1;
	}
}

void InitUsedMarkArr ()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		used[i] = false;
	}
}


void CopySrc_string_2_int ()
{
	src_value = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			src_value *= 2;
			src_value += (src_str[i][j] == '+' ? 1 : 0);
		}
	}
	//cout << src_value << endl;
}

void TranslateWay (int ID)
{
	int x, y;
	x = 1;
	y = 0;
	while (ID > 4)
	{
		ID -= 4;
		x++;
	}
	y = ID;
	cout << x << " " << y << endl;
}

void Output (Node* p_current)
{
	if (NULL != (*p_current).p_pre)
	{
		Output ((*p_current).p_pre);
		TranslateWay ((*p_current).way);
	}
}

void BFS_Search ()
{
	run_map = new Node*[MAX_SIZE];
	run_map[0] = new Node[1];
	run_map[0][0].value = src_value;
	run_map_index[0] = 0;
	//---- start BFS Searching.
	bool bFlag = true;
	int searching_level = 0;
	while (bFlag)
	{
		//---------------------------------------------------------//
		bFlag = false;
		searching_level++;
		//---------------------------------------------------------//
		run_map[searching_level] 
			= new Node[16 * (run_map_index[searching_level - 1] + 1)];
		for (int i = 0; i <= run_map_index[searching_level - 1]; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				int tmp_value;
				tmp_value = 
						run_map[searching_level-1][i].value 
					^ 
						xor_index[j];
				if (!used[tmp_value])
				{
					bFlag = true;
					used[tmp_value] = true;
					run_map_index[searching_level]++;
					run_map[searching_level]
						[run_map_index[searching_level]].value=tmp_value;
					run_map[searching_level]
						[run_map_index[searching_level]].way   = j;
					run_map[searching_level]
						[run_map_index[searching_level]].p_pre = 
							&run_map[searching_level-1][i];
					if (tmp_value == 0)
					{
						//---- Output 
						cout << searching_level << endl;
						Output (
							&run_map
							[searching_level]
							[run_map_index[searching_level]]
							);
						//--------------------------------------------
						return;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------//
int main ()
{
	while (
		cin >> src_str[0]
			>> src_str[1]
			>> src_str[2]
			>> src_str[3]
	)
	{
		InitXorIndex ();
		CopySrc_string_2_int ();
		InitRunMapIndex ();
		InitUsedMarkArr ();
		BFS_Search ();
	}
	return 0;
}


