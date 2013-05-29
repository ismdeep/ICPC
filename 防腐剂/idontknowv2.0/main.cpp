#include <iostream>
#include <cstring>
using namespace std;

/////////////////////////////////////////////////////////////////
// 数据定义与申明部分
#define MOD  10007
#define MAXK 1000000
typedef unsigned long long int lInt;
lInt iAnswer;
lInt a, k;

/////////////////////////////////////////////////////////////////
// 函数定义部分

lInt iFac(int time) // 计算 a ^ time
{
    if (time == 1)
    {

        return a % MOD;
    }
    else
    {
        int tmp_return;
        tmp_return = iFac(time / 2) % MOD;
        tmp_return = ((tmp_return) * tmp_return) % MOD;
        if (time % 2 == 1)
        {
            tmp_return *= a;
            tmp_return %= MOD;
        }
        return tmp_return % MOD;
    }
}

lInt iGetAnswer(int time)
{
    if (time == 1)
    {
        return a % MOD;
    }
    else
    {
        lInt tmp_result = 0;

        if (time % 2 == 0)
        {
            tmp_result  = iGetAnswer(time/2) % MOD;
            tmp_result *= (1 + iFac(time/2));
            tmp_result %= MOD;
        }
        else
        {
            tmp_result  = iGetAnswer((time-1)/2) % MOD;
            tmp_result *= (1 + iFac((time-1)/2));
            tmp_result %= MOD;
            tmp_result += iFac(time);
            tmp_result %= MOD;
        }
        return tmp_result;
    }
}
/////////////////////////////////////////////////////////////////
//main()
int main()
{
    while (cin >> a >> k)
    {
        cout << iGetAnswer(k) << endl;
    }
}

// end
// ism



