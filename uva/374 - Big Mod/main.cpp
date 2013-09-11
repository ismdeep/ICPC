#include <iostream>
using namespace std;

typedef unsigned long long int _long_int_;

_long_int_ _pow_mod_ (_long_int_ b, _long_int_ p, _long_int_ m)
{
	if (0 >= p)
	{
		return 1;
	}
	else if (1 == p)
	{
		return b % m;
	}
	else
	{
		_long_int_ tmp;
		tmp = _pow_mod_ (b, p / 2, m);
		tmp = tmp * tmp;
		tmp %= m;
		tmp *= _pow_mod_ (b, p % 2, m);
		tmp %= m;
		//cout << "-- " << tmp << endl;
		return tmp;
	}
}

int main ()
{
	_long_int_ a, b, c;
	while (cin >> a >> b >> c)
	{
		cout << _pow_mod_ (a, b, c) << endl;
	}
	return 0;
}


