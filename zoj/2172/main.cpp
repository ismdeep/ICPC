#include <iostream>
using namespace std;

int main()
{
    int n;
	int set;
	set = 0;
	while (cin >> n && n > 0)
	{
	    string *str;
		str = new string[n];
		for (int i = 0; i < n ; i++)
		{
		    cin >> str[i];
		}
		
		// output set ID and set information
		set++;
		cout << "SET " << set << endl;
		
		// output array of string_s from left  to right
		for (int i = 0; i < n; i += 2)
		{
		    cout << str[i] << endl;
		}
		// output array of string_s from right to left
		
		int top;
		if (n % 2 == 0)
		{
		    top = n - 1;
		}
		else
		{
		    top = n - 2;
		}
		
		for (int i = top; i >= 0; i -= 2)
		{
		    cout << str[i] << endl;
		}
		
		delete[] str;
	}
	
	return 0;
}

// end 
// ism 
