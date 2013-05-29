// Project name : 1952 ( BUY LOW,BUY LOWER ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 15:08:20 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int* a = new int[n + 1]; // 存储原始数据
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        a[n] = -1;

        int* count;  // 计数，表示到达当前状态的路径数目
        int* length; // 计数，当前最长字串

        count  = new int[n + 1];
        length = new int[n + 1];

        count[0]  = 1;
        length[0] = 1;

        // start dp
        for (int i = 1; i <= n; i++)
        {
            int tmp_max_count  = 0;
            int tmp_max_length = 0;
            for (int j = 0; j < i; j++)
            {
                if (a[j] > a[i])
                {
                    if (tmp_max_length < length[j])
                    {
                        tmp_max_length = length[j];
                        tmp_max_count  = count[j];
                    }
                    else if (tmp_max_length == length[j])
                    {
                        bool found_same = false;
                        for (int k = 0; !found_same && k < j; k++)
                        {
                            if (a[j] == a[k])
                            {
                                found_same = true;
                            }
                        }
                        if (!found_same)
                        {
                            tmp_max_count += count[j];
                        }
                    }
                    else
                    {
                        // doing nothing just throw the case of a[j]
                    }
                }
            }

            count[i]  = tmp_max_count;
            length[i] = tmp_max_length + 1;

            if (count[i] == 0)
            {
                count[i] = 1;
            }
        }

        // output for test case
        // output lenght
        /*
        for (int i = 0; i < n; i++)
        {
            cout << length[i] << " ";
        }
        cout << endl;
        // output count
        for (int i = 0; i < n; i++)
        {
            cout << count[i]  << " ";
        }
        cout << endl;

        */

        cout << length[n] - 1 << " " << count[n] << endl;;
    }
    return 0;
}

// end 
// ism 

