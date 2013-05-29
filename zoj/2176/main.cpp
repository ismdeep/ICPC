#include <iostream>
using namespace std;

int main()
{
    int n;
	while (cin >> n && n > 0)
	{
	    int *value;
		int *count;
		value = new int[n];
		count = new int[n];
		
		// input data
		for (int i = 0; i < n; i++)
		{
		    cin >> value[i] >> count[i];
		}
		
		for (int i = n - 1; i >= 1; i--)
		{
		    count[i] -= count[i-1];
		}
		
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
		    sum += (value[i] * count[i]);
		}
		
		cout << sum << " miles" << endl;
		// free memory
		delete[] value;
		delete[] count;
	}
	
	return 0;
}

// end 
// ism
