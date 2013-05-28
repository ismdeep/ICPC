// Project name : 航线设置
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul 15 16:33:54 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1010

struct FriendCity
{
    int a, b;
};

bool cmp(FriendCity fa, FriendCity fb)
{
    if (fa.a < fb.a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

FriendCity map[MAXN];

int reg[MAXN];

int n;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i].a >> map[i].b;
    }

    sort(map + 1, map + n + 1, cmp);
}

void dp()
{
    reg[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j < i; j++)
        {
            if (map[j].b < map[i].b && max < reg[j])
            {
                max = reg[j];
            }
        }
        reg[i] = max + 1;
    }
}

int getResult()
{
    int max_tmp = reg[1];
    for (int i = 2; i <= n; i++)
    {
        if (reg[i] > max_tmp)
        {
            max_tmp = reg[i];
        }
    }
    return max_tmp;
}


int main()
{
    int time = 0;
    while (cin >> n)
    {

        time++;
        init();
        dp();
        cout << "Case " << time << ":" << endl;
        cout << "The Maximal number is: " << getResult() <<endl;
    }
    return 0;
}

// end 
// ism 

