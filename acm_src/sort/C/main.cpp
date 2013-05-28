// Project name : C ( Number Steps ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 21:58:22 2012


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

// end 
// ism 

