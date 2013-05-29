#include <stdio.h>

int cal_ans (int value)
{
	int count_times = 0;
	int tmp = 1;
	while (tmp < value)
	{
		count_times++;
		tmp *= 2;
	}
	return count_times;
}


int main ()
{
	int case_index = 0;
	int n;
	while (scanf ("%d", &n) != EOF, -1 != n)
	{
		printf ("Case %d: %d\n", ++case_index, cal_ans(n));
	}
}


