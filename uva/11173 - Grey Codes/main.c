/*
 * Problem ID : 11173
 *
 * User : ismdeep
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long int LL;

LL _2_pow_[50];

void init_2_pow ()
{
	int i;
	_2_pow_[0] = 2;
	for (i = 1; i < 50; i++)
	{
		_2_pow_[i] = _2_pow_[i-1] * 2;
	}
}

int main ()
{
	int t, i, digital, n, k;
	LL ans = 0;
	init_2_pow ();
	scanf ("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf ("%d%d", &n, &k);
		for (digital = n; digital >= 1; digital--)
		{
			LL mod_value = k % _2_pow_[digital];
			if (
				   ((mod_value - (_2_pow_[digital] / 4)) >= 0)
				&& ((mod_value + (_2_pow_[digital] / 4)) < _2_pow_[digital])
			)
			{
				ans *= 2;
				ans ++;
			}
			else
			{
				ans *= 2;
			}
		}
		printf ("%I64d\n", ans);
	}
	return 0;
}


