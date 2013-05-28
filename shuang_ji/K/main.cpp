/* 
 * Project Name : K
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 15:19:33 2012 
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

struct Node
{
	int m;
	int v;
	int p;
	int mv;
	int mp;
	int vp;
	int mvp;
	//
	int value;
};

Node iData[50][50][50];
int value_m, value_v, value_p, value_mv, value_mp, value_vp, value_mvp;

void make_iData ()
{
	memset (iData, 0, sizeof(iData));
	//---------------------------------------------------------------------------------------------//
	for (int i = 0; i < 50; i++)
	{
		iData[i][0][0].value = value_m * i;
		iData[i][0][0].m   = i;
		iData[i][0][0].v   = 0;
		iData[i][0][0].p   = 0;
		iData[i][0][0].mv  = 0;
		iData[i][0][0].mp  = 0;
		iData[i][0][0].vp  = 0;
		iData[i][0][0].mvp = 0;
	}
	//---------------------------------------------------------------------------------------------//
	for (int i = 1; i < 50; i++)
	{
		for (int j = 1; j < 50; j++)
		{
			iData[i][j][0] = iData[i][j-1][0];
			iData[i][j][0].v++;
			iData[i][j][0].value += value_v;
			//
			Node iTmpNode;
			iTmpNode = iData[i][j-1][0];
			iTmpNode.m--;
			iTmpNode.value -= value_m;
			iTmpNode.mv++;
			iTmpNode.value += value_mv;
			if (iTmpNode.value > iData[i][j][0].value)
			{
				iData[i][j][0] = iTmpNode;
			}
		}
	}
	//---------------------------------------------------------------------------------------------//
	for (int i = 1; i < 50; i++)
	{
		for (int j = 1; j < 50; j++)
		{
			for (int k = 1; k < 50; k++)
			{
				iData[i][j][k] = iData[i][j][k-1];
				iData[i][j][k].p++;
				iData[i][j][k].value += value_p;
				//
				Node iTmpNode;
				//---- mp ----//
				if (iData[i][j][k-1].m > 0)
				{
					iTmpNode = iData[i][j][k-1];
					iTmpNode.m--;
					iTmpNode.value -= value_m;
					iTmpNode.mp++;
					iTmpNode.value += value_mp;
					if (iTmpNode.value > iData[i][j][k].value)
					{
						iData[i][j][k] = iTmpNode;
					}
				}
				//---- vp ----//
				if (iData[i][j][k-1].v > 0)
				{
					iTmpNode = iData[i][j][k-1];
					iTmpNode.v--;
					iTmpNode.value -= value_v;
					iTmpNode.vp++;
					iTmpNode.value += value_vp;
					if (iTmpNode.value > iData[i][j][k].value)
					{
						iData[i][j][k] = iTmpNode;
					}
				}
				//---- mvp ---//
				if (iData[i][j][k-1].m > 0 && iData[i][j][k-1].v > 0)
				{
					iTmpNode = iData[i][j][k-1];
					iTmpNode.m--;
					iTmpNode.value -= value_m;
					iTmpNode.v--;
					iTmpNode.value -= value_v;
					iTmpNode.mvp++;
					iTmpNode.value += value_mvp;
					if (iTmpNode.value > iData[i][j][k].value)
					{
						iData[i][j][k] = iTmpNode;
					}
				}
				//
				//
				//
				//
				//
				//
				//
				//
				//
			}
		}
	}
}

int main () 
{
	while (cin >> value_m >> value_v >> value_p >> value_mv >> value_mp >> value_vp >> value_mvp)
	{
		make_iData ();
		string str;
		cin >> str;
		int count_m, count_v, count_p;
		count_m = 0;
		count_v = 0;
		count_p = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'M')
			{
				count_m++;
			}
			if (str[i] == 'V')
			{
				count_v++;
			}
			if (str[i] == 'P')
			{
				count_p++;
			}
		}
		cout << iData[count_m][count_v][count_p].value << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

