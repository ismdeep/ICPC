/*
 * Project     : 1109
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Aug 25 20:33:40 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// data section
#define MAXN 1000
class Number
{
public:
	int divisor;
	int number;
};
Number num_map[MAXN+1];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// cmp_number
bool cmp_number(Number num_x, Number num_y)
{
	if (num_x.divisor < num_y.divisor)
	{
		return true;
	}
	else if (num_x.divisor == num_y.divisor)
	{
		if (num_x.number > num_y.number)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// make_num_map()
void make_num_map()
{
	for (int i = 1; i <= MAXN; i++)
	{
		num_map[i].number  = i;
		num_map[i].divisor = 1;
	}
	for (int div = 2; div <= MAXN; div++)
	{
		for (int j = div; j <= MAXN; j += div)
		{
			num_map[j].divisor++;
		}
	}
	// sort(num_map[1] , num_map[MAXN]     , cmp_number);
	   sort(num_map + 1, num_map + MAXN + 1, cmp_number);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main function
int main()
{
	make_num_map();
	int t;
	cin >> t;
	for (int case_count = 1; case_count <= t; case_count++)
	{
		cout << "Case " << case_count << ": ";
		int index;
		cin >> index;
		cout << num_map[index].number << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

