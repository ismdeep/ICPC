#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void ism ()
{
	cout << "--------" << endl;
}


const int EAST  = 0;
const int RIGHT = 0;
const int SOUTH = 1;
const int DOWN  = 1;
const int WEST  = 2;
const int LEFT  = 2;
const int NORTH = 3;
const int UP    = 3;
	

const int DONKEY = 0;
const int TIGERR = 1;
	
	
const bool CAN_CAN_GO = true ;
const bool NOT_CAN_GO = false;
	
#define LOCAL_JUDGE
	
	
int dir_plus[4][2] = {
	{ 0,  1},
	{ 1,  0},
	{ 0, -1},
	{-1,  0}
};

int NEXT[2][4] = {{DOWN, LEFT, UP, RIGHT}, {UP, RIGHT, DOWN, LEFT}};

class AnimalGoingOn
{
public:
	int ID;
	int x;
	int y;
	int dir;
		
	bool map[1100][1100];
		
	void set_map (int n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				this->map[i][j] = CAN_CAN_GO;
			}
		}
		
		for (int i = 0; i <= n + 1; i++)
		{
			this->map[0][i] = NOT_CAN_GO;
			this->map[n+1][i] = NOT_CAN_GO;
			this->map[i][0] = NOT_CAN_GO;
			this->map[i][n+1] = NOT_CAN_GO;
			
		}
		
		this->map[this->x][this->y] = NOT_CAN_GO;
		
	};
		
	bool CanFcukingOn ()
	{
		bool can_fcuking_on = false;
		if (CAN_CAN_GO == map[x+dir_plus[this->dir][0]]
							 [y+dir_plus[this->dir][1]])
		{
			can_fcuking_on = true;
			this->x += dir_plus[this->dir][0];
			this->y += dir_plus[this->dir][1];
		}
		else
		{
			if (CAN_CAN_GO == map[x+dir_plus[NEXT[this->ID][this->dir]][0]]
								 [y+dir_plus[NEXT[this->ID][this->dir]][1]]
			)
			{
				can_fcuking_on = true;
				this->x += dir_plus[NEXT[this->ID][this->dir]][0];
				this->y += dir_plus[NEXT[this->ID][this->dir]][1];
				this->dir = NEXT[this->ID][this->dir];
			}
		}
		return can_fcuking_on;
	};
		
		
};


int main()
{
	// TODO Input data
	int n;
	cout << "ism" << endl;
	while (scanf ("%d", &n) , n)
	{
		AnimalGoingOn donkey;
		AnimalGoingOn tigerr;
		int dx, dy, dd;
		int tx, ty, td;
		scanf ("%d%d%d%d%d%d", &dx, &dy, &dd, &tx, &ty, &td);

		donkey.x = dx + 1;
		donkey.y = dy + 1;
		donkey.dir = dd;
		tigerr.x = tx + 1;
		tigerr.y = ty + 1;
		tigerr.dir = td;

		donkey.ID = DONKEY;
		donkey.set_map(n);

		tigerr.ID = TIGERR;
		tigerr.set_map(n);
		
		bool STOP = false;
		while (!STOP & (tigerr.CanFcukingOn() | donkey.CanFcukingOn()))
		{
			if (donkey.x == tigerr.x && donkey.y == tigerr.y)
			{
				printf ("%d %d\n", donkey.x - 1, donkey.y - 1);
				STOP = true;
			}
		}
		
		if (!STOP)
		{
			if (donkey.x == tigerr.x && donkey.y == tigerr.y)
			{
				printf ("%d %d\n", donkey.x - 1, donkey.y - 1);
				STOP = true;
			}
			else
			{
				printf("%d\n", -1);
			}
		}
	}
	return 0;
}
