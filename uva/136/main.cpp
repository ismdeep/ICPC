#include <iostream>
using namespace std;

bool judge (int value)
{
	while (value % 2 == 0) {value /= 2;}
	while (value % 3 == 0) {value /= 3;}
	while (value % 5 == 0) {value /= 5;}
	if (value == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main ()
{
	int value_index = 1;
	for (int count = 1; count <= 1500; count++)
	{
		cout << count << " --> ";
		while (!judge(value_index))
		{
			value_index++;
		}
		cout << value_index << endl;
		value_index++;
	}
	return 0;
}


