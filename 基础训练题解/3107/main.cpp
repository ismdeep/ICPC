#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        cin >> n;
        int *a = new int[n];
        int sum = 0;
        
        // input data numbers that everyone own the apple 
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //cout << "ism " << endl;
        int current = 0;
        
        for(int i = 0; i < n; i++)
        {
            while( a[i] < 0 )
            {
                if(a[current] <= 0)
                {
                    current++;
                }
                else
                {
                    if((0-a[i]) <= a[current])
                    {
                        sum += fabs(current-i)*(0-a[i]);
                        a[current] -= (0-a[i]);
                        a[i] = 0;
                    }
                    else
                    {
                        sum += fabs(current-i)*(a[current]);
                        a[i] += a[current];
                        a[current] = 0;
                        current++;
                    }
                    
                }
            }
        }
        
        cout << sum << endl;
        
        delete[] a;
    }
    
    return 0;
}
//end
//ism

