#include <iostream>
using namespace std;

int cal_ans (int value)
{
	int count_times = 0;
	int tmp = 1;
	while (tmp < value)
	{
		count_times++;
		tmp *= 2;
	}
	//cout << "--- " << count_times << " " << tmp << endl;
	return count_times;
}


int main ()
{
	int case_index = 0;
	int n;
	while (cin >> n, -1 != n)
	{
		cout << "Case " << ++ case_index << ": " << cal_ans (n) << endl;
	}
}


