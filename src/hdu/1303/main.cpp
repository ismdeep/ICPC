// Project name : 1303 ( Doubles ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 19:20:51 2012


#include <iostream>
using namespace std;

int main()
{
    int a[1000];
	int top = -1;
	int num;
	while (cin >> num && num != -1)
	{
		top = -1;
		top++;
		a[top] = num;
		while (cin >> num && num)
		{
		    top++;
			a[top] = num;
		}

		// search it to get the answer
		int count = 0;
		for (int i = 0; i <= top; i++)
		{
		    for (int j = 0; j <= top; j++)
			{
			    if (a[i] * 2 == a[j])
				{
				    count++;
				}
			}
		}
		cout << count << endl;
	}
    return 0;
}

// end 
// ism 

