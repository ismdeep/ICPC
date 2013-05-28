// Project name : sort
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 21:11:33 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    if (a > b)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        sort(a, a + n, cmp);
        
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        cout << a[n - 1] << endl;
        
    }
    return 0;
}

// end 
// ism 

