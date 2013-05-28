#include <iostream>
using namespace std;

int main()
{
    int n;
    /* input a number n ,which stands there are n numbers should input later */
    cin >> n;
    int *a = new int[n];
    
    /* input n numbers to be processed */
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int bottom = 0;
    int top = n - 1;
    
    /* when bottom > top,process stop!! */
    while (bottom <= top)
    {
        if( a[bottom] == 0 )
        {
            for(int j = bottom; j < top; j++)
            {
                a[j] = a[j+1];
            }
            top--;
        }
        else
        {
            bottom++;
        }
    }
    
    /* output the result */
    for(int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    delete[] a;
    return 0;
}
