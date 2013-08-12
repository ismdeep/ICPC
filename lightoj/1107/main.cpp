/*
 * Project     : 1107
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 14:16:29 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

class Land
{
public:
	int x1, y1;
	int x2, y2;
	bool is_in_land(int x, int y);
	void input_data();
};

bool Land::is_in_land(int x, int y)
{
	// judge it
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Land::input_data()
{
	cin >> x1 >> y1 >> x2 >> y2;
}

int main()
{
	int t;
	cin >> t;
	for (int case_count = 1; case_count <= t; case_count++)
	{
		cout << "Case " << case_count << ":" << endl;
		Land land;
		land.input_data();
		int count;
		cin >> count;
		while (count--)
		{
			int x, y;
			cin >> x >> y;
			if (land.is_in_land(x, y))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No"  << endl;
			}
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

