/*
 * main.cpp
 *
 *  Created on: May 9, 2014
 *      Author: ismdeep
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXN 2000

int a[MAXN];
int b[MAXN];
int count_a_lcs[MAXN];
int a_n;
int b_n;
int dp[100][100];
int lcs_index;
int lcs_len;
int arr[MAXN];

bool cmp_first (int a, int b)
{
	return (a > b)?true:false;
}

bool cmp_second (int a, int b)
{
	if ((a % 10) == (b % 10))
	{
		return (a < b)?true:false;
	}
	else
	{
		return ((a%10) < (b%10))?true:false;
	}
}

void delete_the_shit ()
{
	// delete the shit.
	int index = 0;
	for (int i = 1; i < a_n; i++)
	{
		if (a[i-1] != a[i])
		{
			index++;
			a[index] = a[i];
		}
	}
	a_n = index+1;
	index = 0;
	for (int i = 1; i < b_n; i++)
	{
		if (b[i-1] != b[i])
		{
			index++;
			b[index] = b[i];
		}
	}
	b_n = index+1;
}



void LCS ()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<a_n;i++)
		for(int j=0;j<b_n;j++)
		{
			if(a[i]==b[j])
				dp[i+1][j+1]=dp[i][j]+1;
		}
	int mx=-1;
	int id;
	for(int i=0;i<a_n;i++)
		for(int j=0;j<b_n;j++)
		{
			if(dp[i+1][j+1]>mx)
			{
				mx=dp[i+1][j+1];
				id=i-mx+1;
			}
		}
	// id...
	// mx
	lcs_index = id;
	lcs_len   = mx;
}


void get_lcs_arr ()
{
	for (int i = 0; i < lcs_len; i++)
	{
		arr[i] = a[lcs_index+i];
	}

}

int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a_n >> b_n;
		for (int i = 0; i < a_n; i++)
		{
			cin >> a[i];
		}
		sort (a,a+a_n,cmp_first);
		for (int i = 0; i < b_n; i++)
		{
			cin >> b[i];
		}
		sort (b,b+b_n,cmp_first);
		delete_the_shit();
		LCS ();
		if (lcs_len <= 0)
		{
			cout << "NONE" << endl;
		}
		else
		{

			get_lcs_arr();
			for (int i = 0; i < lcs_len; i++)
			{
				if (i)
				{
					cout << " ";
				}
				cout << arr[i];
			}
			cout << endl;
			sort (arr,arr+lcs_len,cmp_second);
			for (int i = 0; i < lcs_len; i++)
			{
				if (i)
				{
					cout << " ";
				}
				cout << arr[i];
			}
			cout << endl;
		}
		// --------------------------------------------------

	}
	return 0;
}


