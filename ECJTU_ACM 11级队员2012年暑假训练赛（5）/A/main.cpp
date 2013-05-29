#include <iostream>
using namespace std;

int m, a, b, c, d, e, f, g, h, i, j, k ;

int iCalSunny(int day)
{
    return (a * day * day + b * day + c);
}

int iCalCloudy(int day)
{
    return (d * day * day + e * day + f);
}

int iCalRaining(int day)
{
    return (g * day * day + h * day + i);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int gotmoney = 0;
        cin >> m >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k;
        bool isFull = false;
        int day;
        for (day = 1; !isFull; day++)
        {
            if ((j * day + k)%3 == 0)
            {
                gotmoney += iCalSunny(day);
            }
            else if ((j*day + k) % 3 == 1)
            {
                gotmoney += iCalCloudy(day);
            }
            else
            {
                gotmoney += iCalRaining(day);
            }
            if (gotmoney >= m)
            {
                isFull = true;
            }
        }
        cout << day-1 << endl;
    }
}
