//project name: 1391 (Number Steps)
//File name:main.cpp
//Author:键盘杀手
//Creat Date & Time:Fri May  4 15:46:03 2012

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while( t-- )
    {
        int x, y;
        cin >> x >> y;
        
        if( x==y && x%2==0 )
        {
            cout << 2*x << endl;
        }
        else if( x==y && x%2==1 )
        {
            cout << (2*(x-1))+1 << endl;
        }
        else if( x-y==2 && x%2==0 )
        {
            cout << (2*(x-2))+2 << endl;
        }
        else if( x-y==2 && x%2==1)
        {
            cout << (2*(x-3))+3 << endl;
        }
        else
        {
            cout << "No Number" << endl;
        }
        
    }
    
    return 0;
}
//end
//ism
