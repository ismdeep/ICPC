#include <iostream>
using namespace std;

int main()
{
    int time;
    time = 1;
    int n;
    while( cin >> n && n )
    {
        int *a = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        
        sum = sum / n;
        
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            a[i] = a[i] - sum;
            if(a[i] > 0)
            {
                result += a[i];
            }
        }
        
        
        cout << "Set #" << time << endl;
        cout << "The minimum number of moves is ";
        cout << result << "." << endl << endl;
        time ++;
    }
    
    return 0;
}

// end 
// ism 

