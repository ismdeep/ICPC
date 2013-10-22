#include <iostream>
using namespace std;

typedef unsigned long long int longint;

int has_day[1002];
int big_month   = 20;
int small_month = 19;

bool CIsSpecialYear(int year)
{
    if (year % 3 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CInitForArrayHasDay()
{
    for (int year = 1; year <= 1000; year++)
    {
        if (CIsSpecialYear(year))
        {
            has_day[year] = 10 * big_month;
        }
        else
        {
            has_day[year] = 5 * big_month + 5 * small_month;
        }
    }
}

longint CalToMillennium(int year, int month, int day)
{
    int ans = 0;

    for (int i = month + 1; i <= 10; i++)
    {
        if (CIsSpecialYear(year))
        {
            ans += 20;
        }
        else
        {
            if (i % 2 == 0)
            {
                ans += small_month;
            }
            else
            {
                ans += big_month;
            }
        }
    }

    if (CIsSpecialYear(year))
    {
        ans += (big_month - day);
    }
    else
    {
        if (month % 2 == 0)
        {
            ans += (small_month - day);
        }
        else
        {
            ans += (big_month - day);
        }
    }

    for (int i = year + 1; i <= 999; i++)
    {
        ans += has_day[i];
    }

    ans++;

    return ans;
}

int main()
{
    CInitForArrayHasDay();
    int t;
    cin >> t;
    while (t--)
    {
        int year, month, day;
        cin >> year >> month >> day;
        cout << CalToMillennium(year, month, day) << endl;
    }

    return 0;
}

// end
// ism
