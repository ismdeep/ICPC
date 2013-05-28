#include <iostream>
using namespace std;

#define MAP_SIZE 4
#define COUNT_SIZE 100000

int xor_index[17];

int count_level[COUNT_SIZE];
int current_value_arr[COUNT_SIZE];
int current_value_arr_index;

int tmp_value_arr[COUNT_SIZE];
int tmp_value_arr_index;

int src_value;
int des_value;

void InitXorIndex ()
{
	xor_index[1 ] = 51200;
	xor_index[2 ] = 58368;
	xor_index[3 ] = 29184;
	xor_index[4 ] = 12544;
	xor_index[5 ] = 35968;
	xor_index[6 ] = 20032;
	xor_index[7 ] = 10016;
	xor_index[8 ] = 4880 ;
	xor_index[9 ] = 2248 ;
	xor_index[10] = 1252 ;
	xor_index[11] = 626  ;
	xor_index[12] = 305  ;
	xor_index[13] = 140  ;
	xor_index[14] = 78   ;
	xor_index[15] = 39   ;
	xor_index[16] = 19   ;
}

void InitCountLevel ()
{
	for (int i = 0; i < COUNT_SIZE; i++)
	{
		count_level[i] = -1;
	}
}

void SetSrcValue ()
{
	src_value = 0;
	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 4; j++)
		{
			src_value *= 2;
			if (str[j] == 'b')
			{
				src_value += 1;
			}
			else
			{
				src_value += 0;
			}
		}
	}
#ifdef _I_STACK_DEBUG_
	cout << src_value << endl;
#endif
}

void SetDesValue ()
{
	des_value = 65535;
}

bool IsDes (int n_value)
{
	return (n_value == 0 || n_value == des_value);
}

void BFS_Search ()
{
	current_value_arr[0] = src_value;
	current_value_arr_index = 0;
	count_level[src_value] = 0;
	if (IsDes(src_value))
	{
		cout << "0" << endl;
		return ;
	}
	//---------------------------------
	bool bFlag = true;
	int level_count = 0;
	while (bFlag)
	{
		level_count++;
		bFlag = false;
		int tmp_value;
		tmp_value_arr_index = -1;
		for (int i = 0; i <= current_value_arr_index; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				tmp_value = current_value_arr[i] ^ xor_index[j];
#ifdef _I_STACK_DEBUG_
				cout << tmp_value << endl;
#endif
				if (-1 == count_level[tmp_value])
				{
					if (IsDes(tmp_value))
					{
						cout << level_count << endl;
						return ;
					}
					bFlag = true;
					tmp_value_arr_index++;
					tmp_value_arr[tmp_value_arr_index] = tmp_value;
					count_level[tmp_value] = level_count;
				}
			}
		}
		current_value_arr_index = tmp_value_arr_index;
		for (int i = 0; i <= tmp_value_arr_index; i++)
		{
			current_value_arr[i] = tmp_value_arr[i];
		}
	}
	cout << "Impossible" << endl;
}

int main ()
{
	InitCountLevel ();
	InitXorIndex ();
	SetSrcValue ();
	SetDesValue ();
	BFS_Search ();
	return 0;
}


