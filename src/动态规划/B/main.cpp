// Project name : B ( 青蛙的约会 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 11 09:55:27 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 exgcd(int64 m, int64& x, int64 n, int64& y)
{
	int64 x1, y1, x0, y0;

	x0 = 1; y0 = 0;
	x1 = 0; y1 = 1;

	int64 r = (m % n + n) % n;
	int64 q = (m - r) / n;
	x= 0; y = 1;

	while (r)
	{
		x  = x0 - q * x1;
		y  = y0 - q * y1;
		x0 = x1;
		y0 = y1;

		x1 = x; y1 = y;
		m = n; n = r; r = m % n;
		q  = (m - r) / n;
	}
	return n;
}
int main()
{
    int yy;
	int64 r, t;
	int64 x, y, m, n, l;
	int64 ar, br, cr;
	cin >> x >> y >> m >> n >> l;
	int64 M = exgcd(n - m, ar, l, br);
	if ((x - y) % M || m == n)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		int64 s = l / M;
		ar = ar * ((x - y) / M);
		ar = (ar % s + s) % s;
		cout << ar << endl;
	}
    return 0;
}

// end 
// ism 

