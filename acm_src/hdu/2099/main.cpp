// Project name : 2099 ( 整除的尾数 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 20:06:14 2012


#include <iostream>
using namespace std;

int main()
{
    int n, k;
	while (cin >> n >> k && n + k)
	{
		int tmp = (n * 100) % k;

	    if (tmp != 0)
		{
			tmp = k - tmp;
		}

		int count = 0;
		while (tmp < 100)
		{
		    if (tmp < 10)
			{
			    cout << "0";
			}
			if (count)
			{
			    cout << " ";
			}
			count++;
			cout << tmp;
			tmp += k;
		}
		cout << endl;
	}
    return 0;
}

// end 
// ism 

