#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        char op;
        cin >> op;
        int x, y;
        cin >> x >> y;
        if( op == '+' )
        {
            cout << x + y << endl;
        }
        
        if( op == '-' )
        {
            cout << x - y << endl;
        }
        
        if( op == '*' )
        {
            cout << x * y << endl;
        }
        
        if( op == '/' )
        {
            if(x % y == 0)
            {
                int result = x / y;
                cout << result << endl;
            }
            else
            {
                printf("%.2f\n",(double)x/y);
            }
        }
        
    }
}
