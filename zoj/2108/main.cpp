#include <iostream>
using namespace std;

int main()
{
    int n;
	while (cin >> n && n > 0)
	{
	    int *num = new int[n+1];
		num[0] = 0;
		for(int i=1;i<=n;i++ )
		{
		    cin >> num[i];
		}
        int a = 0, b = 0;
        for(int i=1;i<=n;i++ )
        {
            if( num[i]-num[i-1]>0 ) a+=num[i]-num[i-1];
            else b+=num[i-1]-num[i];
        }
        cout << 6 * a + 4 * b + 5 * n << endl;
		
		delete[] num;
	}
	
	return 0;
}

// end 
// ism 
/*************************/
