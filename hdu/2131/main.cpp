//project name:2131
//File name:main.cpp
//Author:键盘杀手
//Creat Date & Time:Fri May  4 16:08:44 2012

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char ch;
    string s;
    while( cin >> ch >> s )
    {
        if( ch >= 'A' && ch <= 'Z' )
        {
            ch += 32;
        }
        
        int top = 0;
        int count = 0;
        while(s[top] != '\0' )
        {
            if( ch == s[top] )
            {
                count++;
            }
            else if(ch == (s[top]+32) )
            {
                count++;
            }
            
            top++;
            
        }
        
        printf("%.5f\n",(double)count/top);
        
    }
    return 0;
}
//end
//ism
