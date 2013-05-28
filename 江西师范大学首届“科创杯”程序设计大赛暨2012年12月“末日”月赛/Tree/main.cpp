#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 2000000
int iMap[MAXN];
int Height;

void make_iMap ()
{
	for (int i = 0; i < MAXN; i++)
	{
		iMap[i] = i;
	}
}

void left_root_right (int iIndex, int level)
{
	if (level <= Height)
	{
		left_root_right (iIndex * 2, level + 1);
		printf ("%d ", iMap[iIndex]);
		left_root_right (iIndex * 2 + 1, level + 1);
	}
}

void root_left_right (int iIndex, int level)
{
	if (level <= Height)
	{
		printf ("%d ", iMap[iIndex]);
		root_left_right (iIndex * 2, level + 1);
		root_left_right (iIndex * 2 + 1, level + 1);
	}
}

void left_right_root (int iIndex, int level)
{
	if (level <= Height)
	{
		left_right_root (iIndex * 2, level + 1);
		left_right_root (iIndex * 2 + 1, level + 1);
		printf ("%d ", iMap[iIndex]);
	}
}

int main ()
{
	make_iMap ();
	while (cin >> Height)
	{
		root_left_right (1, 1);
		printf ("\n");
		left_root_right (1, 1);
		printf ("\n");
		left_right_root (1, 1);
		printf ("\n");
	}
	return 0;
}
