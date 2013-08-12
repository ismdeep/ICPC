// project name : 1390 (Binary Numbers)
//File name:main.cpp
//Author:键盘杀手
//Creat Date & Time:Fri May  4 15:28:48 2012

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        cin >> n;
        int c = 0;
        int count = 0;
        while( n )
        {
            if( n%2 == 1 )
            {
                if(c){cout << " ";}
                c++;
                
                cout << count ;
            }
            count++;
            n = n / 2;
        }
        
        cout << endl;
    }
    return 0;
}
//end
//ism
