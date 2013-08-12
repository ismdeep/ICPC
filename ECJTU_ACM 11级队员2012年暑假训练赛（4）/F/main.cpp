#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100
// head begin
typedef unsigned long long int longint;
// head end


int num, lenth;

longint a[MAXN];

bool cmp(longint x, longint y)
{
    return x > y ? true : false;
}

void init()
{
    a[0] = num;
}

longint CGetNextNumber(longint number)
{
    longint ans;

    longint tmp_array[MAXN];

    for (int i = 0; i < lenth; i++)
    {
        tmp_array[i] = number % 10;
        number      /= 10;
    }

    sort(tmp_array,tmp_array + lenth,cmp);

    longint max, min;
    max = 0;
    min = 0;
    for (int i = 0; i < lenth; i++)
    {
        max *= 10;
        max += tmp_array[i];
    }

    for (int i = lenth - 1; i >= 0; i--)
    {
        min *= 10;
        min += tmp_array[i];
    }
    ans = max - min;
    return ans;
}

void CGetAnswerAndOutput()
{
    int start, same_num, end;
    bool found = false;
    for (int i = 0; !found && i <= MAXN - 2; i++)
    {
        for (int j = i + 1; !found && j < MAXN; j++)
        {
            if (a[i] == a[j])
            {
                start    = i;
                end      = j;
                same_num = a[i];
                found = true;
            }
        }
    }

    cout << start << " " << same_num << " " << end - start << endl;


}

int main()
{
    while (cin >> num >> lenth && num + lenth)
    {
        init();
        for (int i = 1; i < MAXN; i++)
        {
            a[i] = CGetNextNumber(a[i-1]);
        }

        CGetAnswerAndOutput();
    }

    return 0;
}

// end
// ism
