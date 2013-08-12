#include <iostream>
#include "Point.h"

using namespace std;


///////////////////////////////////////////////////////////
Point::Point ()
{
	this->x = 0;
	this->y = 0;
	this->used = false;
	for (int i = 0; i < DIR_COUNT; i++)
	{
		this->dir[i] = CAN_GO;
	}
}

///////////////////////////////////////////////////////////
void Point::set_point (int x, int y)
{
	this->x = x;
	this->y = y;
}

///////////////////////////////////////////////////////////
void Point::set_value (char ch_flag)
{
	if (ch_flag == ch_block)
	{
		this->value = BLOCK;
	}
	if (ch_flag == ch_blank)
	{
		this->value = BLANK;
	}
}
///////////////////////////////////////////////////////////
int Point::get_x ()
{
	return this->x;
}


///////////////////////////////////////////////////////////
int Point::get_y ()
{
	return this->y;
}


