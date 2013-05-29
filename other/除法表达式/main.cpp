// Project name : 除法表达式
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul 12 13:34:50 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 11000

typedef unsigned long long int int64;

int64 gcd(int64 a, int64 b)
{
    int tmp;
    while (b)
    {
        int tmp;
        tmp = a % b;
        a   = b;
        b   = tmp;
    }

    return a;
}

void ism()
{
    cout << "--ism" << endl;
}
int num[MAXN];

int main()
{
    string s;
    while (cin >> s)
    {
        // store numbers into array of num[]
        int top = -1;
        int tmp = 0;
        int current = 0;
        while (s[current] != '\0')
        {
            if (s[current] == '/')
            {
                top++;
                num[top] = tmp;
                tmp = 0;
            }
            else
            {
                tmp = tmp * 10 + (s[current] - '0');
            }
            current++;
        }
        top++;
        num[top] = tmp;

        // start process
        num[1] /= gcd(num[0], num[1]);
        
        for (int i = 2; i <= top; i++)
        {
            num[1] /= gcd(num[1], num[i]);
        }
        if (top == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
        if (num[1] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        }
    }

    return 0;
}

// end 
// ism 

