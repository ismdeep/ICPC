// Project name : 1235 ( 统计同成绩学生人数 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul  5 17:20:47 2012


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
	while (scanf("%d", &n) != EOF && n)
	{
	    int* a;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
		    scanf("%d", &a[i]);
		}

		int score;
		scanf("%d", &score);

		int count = 0;
		for (int i = 0; i < n; i++)
		{
		    if (score == a[i])
			{
			    count++;
			}
		}

		cout << count << endl;

	}
    return 0;
}

// end 
// ism 

