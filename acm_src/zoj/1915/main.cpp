// Project name : 1915 ( Above Average ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jun 26 10:33:11 2012


#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        float average = (double)sum / n;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (average < (double)a[i])
            {
                count++;
            }
        }
        
        cout << (double)count*100/sum << "%" << endl;
        
    }
    return 0;
}

// end 
// ism 
