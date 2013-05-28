/* 
 * Project Name : water_cup
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Fri Nov  2 11:40:17 2012 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

#define MAXN 2500000

struct OperatorInstruc
{
	int resource_index;
	int destination_index;
};

OperatorInstruc operator_instruc[7];

void init_operator_instruc ()
{
	operator_instruc[1].resource_index    = 0;
	operator_instruc[1].destination_index = 1;

	operator_instruc[2].resource_index    = 0;
	operator_instruc[2].destination_index = 2;

	operator_instruc[3].resource_index    = 1;
	operator_instruc[3].destination_index = 0;

	operator_instruc[4].resource_index    = 1;
	operator_instruc[4].destination_index = 2;

	operator_instruc[5].resource_index    = 2;
	operator_instruc[5].destination_index = 0;

	operator_instruc[6].resource_index    = 2;
	operator_instruc[6].destination_index = 1;

}


struct State
{
	int cup[3];
};



State state[MAXN];


void show_state (int state_index)
{
	cout << state[state_index].cup[0] << " "
		 << state[state_index].cup[1] << " "
		 << state[state_index].cup[2] << endl;
}



void init_state ()
{
	memset (state, 0, sizeof(state));
	state[0].cup[0] = 12;
	state[0].cup[1] = 0;
	state[0].cup[2] = 0;
}

///////////////////////////////////////////////////////////
bool equal_state (State state_a, State state_b)
{
	return (
			   state_a.cup[0] == state_b.cup[0]
			&& state_a.cup[1] == state_b.cup[1]
			&& state_a.cup[2] == state_b.cup[2]
			);
}

///////////////////////////////////////////////////////////
int level_index[9][2];

void init_level_index ()
{
	level_index[1][0] = 0;
	level_index[1][0] = 0;
	for (int i = 2; i <= 8; i++)
	{
		level_index[i][0] = level_index[i-1][1] + 1;
		level_index[i][1] = level_index[i][0] * 6;
	}
}

///////////////////////////////////////////////////////////
int get_level_left_index (int level)
{
	return level_index[level][0];
}

int get_level_right_index (int level)
{
	return level_index[level][1];
}



///////////////////////////////////////////////////////////
// iMin
int iMin (int a, int b)
{
	return (a < b) ? a : b;
}

///////////////////////////////////////////////////////////
/*
 * This is the kernel of this program.
 *
 * So how can I do to pour water 
 * From state_current to state_des.
 *
 * */
State pour_water (State state_current, OperatorInstruc op)
{
	State state_des;
	state_des = state_current;
	int current_volume;
	int des_volume;
	///////////////////////////////////////////////////////
	// get current_volume
	if (op.resource_index == 0)
	{
		current_volume = 12;
	}
	else if (op.resource_index == 1)
	{
		current_volume = 8;
	}
	else
	{
		current_volume = 5;
	}
	///////////////////////////////////////////////////////
	// get des_volume
	if (op.destination_index == 0)
	{
		des_volume = 12;
	}
	else if (op.destination_index == 1)
	{
		des_volume = 8;
	}
	else
	{
		des_volume = 5;
	}
	///////////////////////////////////////////////////////
	// get pour_volume;
	int pour_volume;
	pour_volume = iMin (
		state_des.cup[op.resource_index],
		des_volume - state_des.cup[op.destination_index]
			);
	state_des.cup[op.resource_index]    -= pour_volume;
	state_des.cup[op.destination_index] += pour_volume;
	return state_des;
}


///////////////////////////////////////////////////////////
/*
 * Oh yeah~~~
 * This is the so called Make BFS process
 * What I did?
 * There are so many problem hr.
 * I don't when I will got the answer.
 * Also I don't know if it can get the answer
 * */

int make_BFS ()
{
	int des_state_index = -1;
	State des_state;
	des_state.cup[0] = 6;
	des_state.cup[1] = 6;
	des_state.cup[2] = 0;
	///////////////////////////////////////////////////////
	bool found = false;
	for (int level = 1; !found && level <= 8; level++)
	{
		int left_index;
		int right_index;
		left_index = get_level_left_index (level);
		right_index = get_level_right_index (level);
		for (
				int iIndex = left_index;
				!found && iIndex <= right_index;
				iIndex++
				)
		{
			for (
					int operator_index = 1;
					!found && operator_index <= 6;
					operator_index++
					)
			{
				///////////////////////////////////////////
				// get the next state by operating
				state[iIndex*6+operator_index] = 
					pour_water (
						state[iIndex],
						operator_instruc[operator_index]
							);
				///////////////////////////////////////////
				// judge if is the des_state
				if (
					true == equal_state (
						des_state, 
						state[iIndex*6+operator_index]
					)
					)
				{
					des_state_index = 
						iIndex * 6 + operator_index;
					found = true;
				}
			}
		}
	}
	return des_state_index;
}

void show_routine (int state_index)
{
	if (0 == state_index)
	{
		show_state (state_index);
	}
	else
	{
		show_routine ((state_index - 1) / 6);
		show_state (state_index);
	}
}

int main () 
{
	init_level_index ();
	init_operator_instruc ();
	init_state ();
	int des_state_index;
	des_state_index = make_BFS ();
	show_routine (des_state_index);
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

