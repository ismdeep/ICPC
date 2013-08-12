#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200

int n;

///////////////////////////////////////////////////
struct Pearls
{
    int need;
    int price;
};

bool cmp(Pearls a, Pearls b)
{
    return a.price < b.price ? true : false;
}

Pearls a[MAXN];

void CInit()
{
    for (int i =  0; i < n; i++)
    {
        cin >> a[i].need >> a[i].price;
    }

    sort(a, a+n, cmp);
}

void CDynamicProgramming()
{
    int ans = 0;// 表示最后的答案
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = i + 1; !found && j < n; j++)
        {
            if (
                (a[i].need + 10 ) * a[i].price + (a[j].need + 10) * a[j].price
                > (a[i].need + a[j].need + 10) * a[j].price
                )
            {
                a[j].need += a[i].need;
                found = true;
            }
        }

        if (!found)
        {
            ans += (a[i].need + 10) * a[i].price;
        }
    }

    cout << ans << endl;
}

///////////////////////////////////////////////////


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        CInit();

        CDynamicProgramming();

    }

    return 0;
}

// end
// ism
