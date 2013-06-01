/*
uva 11636
PROB:  Hello World!
*/


#include <iostream>
using namespace std;

int cal_ans (int value)
{
	int __count__ = 0;
	int tmp = 1;
	while (tmp * 2 < value)
	{
		__count__++;
		tmp *= 2;
	}
	if (tmp != value)
	{
		__count__++;
	}
	return __count__;
}

int main ()
{
	int value;
	int case_index = 0;
	while (cin >> value && value > 0)
	{
		case_index++;
		cout << "Case " << case_index << ": ";
		cout << cal_ans (value) << endl;
	}
	return 0;
}


