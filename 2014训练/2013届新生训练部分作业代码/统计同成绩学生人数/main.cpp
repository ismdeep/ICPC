#include <iostream>

using namespace std;

int main ()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &a[i]);
		}
		int flag_value;
		scanf("%d", &flag_value);
		int _count_ = 0;
		for (int i = 0; i < n; i++)
		{
			if (flag_value == a[i])
			{
				_count_++;
			}
		}
		cout << _count_ << endl;
	}
	return 0;
}