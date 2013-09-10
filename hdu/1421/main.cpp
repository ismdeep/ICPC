// Project name : 1421 ( 搬寝室 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul  3 13:39:38 2012


#include <iostream>
using namespace std;

#define MAXN 2000

class Pare
{
public:
	int x, y; /* make sure that x < y */
	int value;
	bool used;
};

// data
Pare num[MAXN*MAXN];
int top = -1;

int n, k;

int map[MAXN][MAXN];

int a[MAXN];

int cost = 0;
//////////////////////////////////////////////////////////////////
void init_num()
{
    for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < i; j++)
		{
		    top++;
			num[top].x     = i;
			num[top].y     = j;
			num[top].value = map[i][j];
		}
	}
}
//////////////////////////////////////////////////////////////////
void sort_num()
{
    // sort num from 0 ~ top
	for (int i = 0; i < top; i++)
	{
	    int flag = i;
		for (int j = i + 1; j <= top; j++)
		{
		    if (num[j].value < num[flag].value)
			{
			    flag = j;
			}
		}
		Pare pare_tmp;
		pare_tmp  = num[i];
		num[i]    = num[flag];
		num[flag] = pare_tmp;
	}
}
//////////////////////////////////////////////////////////////////
void cal_from_num()
{
	int current = 0;
	for (int time = 0; time < k; time++)
	{
	    cost += (num[current].value * num[current].value);
	    // process for the left data
		for (int i = current + 1; i <= top; i++)
		{
		    if (
				   num[current].x == num[i].x
				|| num[current].x == num[i].y
				|| num[current].y == num[i].x
				|| num[current].y == num[i].y
				)
			{
			    num[i].used = false;
			}
		}
		
		num[current].used = false;
		while (!num[current].used && current <= top)
		{
		    current++;
		}
		
	}
	
}
//////////////////////////////////////////////////////////////////
void input_a_data()
{
    for (int i = 0; i < n; i++)
	{
	    cin >> a[i];
	}
}
//////////////////////////////////////////////////////////////////
void set_all_map_zero()
{
    for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
		{
		    map[i][j] = 0;
		}
	}
}
//////////////////////////////////////////////////////////////////
void process_out_map_value()
{
    for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < i; j++)
		{
		    map[i][j] = (a[i] > a[j]) ? a[i] - a[j] : a[j] - a[i];
		}
	}
}
//////////////////////////////////////////////////////////////////
void output_test()
{
    cout << cost << endl;
}
//////////////////////////////////////////////////////////////////
void set_all_num_unused()
{
    for (int i = 0; i <= top; i++)
	{
	    num[i].used = false;
	}
}
/* main process */
int main()
{
	while (cin >> n >> k)
	{
		set_all_map_zero();
		input_a_data();
		process_out_map_value();
		init_num();
		set_all_num_unused();
		sort_num();
		cal_from_num();
		output_test();
	}
    return 0;
}

// end 
// ism 

