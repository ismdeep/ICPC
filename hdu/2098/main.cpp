#include <iostream>
using namespace std;

#define MAXN 10010

bool iIsPrime[MAXN];

void iMakePrime()
{
    // 素数打表，因为这里素数不是那么多，范围也就10000以内。
    // 这个素数打表有点思维变换的那种 ,,,iIsPrime[i] ,表示i是不是素数，如果为true，则是素数，否则不是。
    for (int i = 0; i < MAXN; i++)
    {
        iIsPrime[i] = true;
    }
    iIsPrime[0] = false;
    iIsPrime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (iIsPrime[i] == true)
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                iIsPrime[j] = false;
            }
        }
    }
}

//////////////////////////////////////////////////////////
// 测试打表是否成功
void iShowIsPrime()
{
    for (int i = 0; i < 100; i++)
    {
        cout << i << " " << iIsPrime[i] << endl;
    }
}

int main()
{
    iMakePrime();
    //iShowIsPrime();

    int iNum;
    while (cin >> iNum && iNum)
    {
        int a, b; // let a + b == iNum
        a = iNum / 2;
        if (iNum % 2 == 0)
        {
            a--;
        }

        int iCount = 0;//计数器，用来表示找到的不同素数的对数的。
        for (int i = 2; i <= a; i++)
        {
            b = iNum - i;// a + b == iNum;
            if (iIsPrime[i] == true && iIsPrime[b] == true)
            {
                // 如果找到相对应的两个都是素数，则计数器加一
                iCount++;
            }
        }
        cout << iCount << endl;
    }
    return 0;
}

// end
// ism

