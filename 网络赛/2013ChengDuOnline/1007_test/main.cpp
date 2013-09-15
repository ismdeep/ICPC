#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;



int cal_fx (int x)
{
	int sum = 0;
	int _2_pow_ = 1;
	while (x)
	{
		sum += ((x % 10) * _2_pow_);
		_2_pow_ *= 2;
		x /= 10;
	}
	return sum;
}


stack<int> _stack_[20000];

int main ()
{
	for (int i = 0; i <= 21474647; i++)
	{
		_stack_[cal_fx(i)].push (i);
	}
	for (int i = 0; i <= 1000; i++)
    {
        cout << i << "->> ";
        cout << _stack_[i].size();
        while (!_stack_[i].empty())
        {
            //cout << _stack_[i].top() << " ";
            _stack_[i].pop();
        }
        cout << endl;
    }
	return 0;
}



