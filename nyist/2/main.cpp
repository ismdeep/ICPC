// Project name : 2
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 10:54:42 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int  n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        
        char a[11010];
        int top = -1;
        int current = 0;
        while (s[current] != '\0')
        {
            if (top < 0)
            {
                top++;
                a[top] = s[current];
            }
            else
            {
                if (   (a[top] == '[' && s[current] == ']') 
                    || (a[top] == '(' && s[current] == ')'))
                {
                    top--;
                }
                else
                {
                    top++;
                    a[top] = s[current];
                }
            }
            current++;
        }

        if (top == -1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
    return 0;
}

// end 
// ism 

