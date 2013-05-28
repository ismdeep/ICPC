#include <iostream>
using namespace std;

#define MAXN 200000
#define MOD 10000007
typedef unsigned long long int longint;

string iStr;
longint* iLength;
int iTop;
int iAns;

void iInit()
{
    iTop = iStr.length();
    iTop--;

    iLength = new longint[iStr.length()];
    if (iStr[0] == 'd')
    {
        iLength[0] = 1;
    }
    else
    {
        iLength[0] = 0;
    }
}

void iDynamicProgramming()
{
    iAns = 0;

    for (int i = 1; i <= iTop; i++)
    {
        if (iStr[i] == 'd')
        {
            iLength[i] = 1;
        }
        if (iStr[i] == 'r')
        {
            int tmp_ans = 0;
            for (int j = 0; j < i; j++)
            {
                if (iStr[j] == 'd')
                {
                    tmp_ans += iLength[j];
                }
            }
            iLength[i] = tmp_ans % MOD;
        }
        if (iStr[i] == 'e')
        {
            int tmp_ans = 0;
            for (int j = 0; j < i; j++)
            {
                if (iStr[j] == 'r')
                {
                    tmp_ans += iLength[j];
                }
            }
            iLength[i] = tmp_ans % MOD;
        }
        if (iStr[i] == 'a')
        {
            int tmp_ans = 0;
            for (int j = 0; j < i; j++)
            {
                if (iStr[j] == 'e')
                {
                    tmp_ans += iLength[j];
                }
            }
            iLength[i] = tmp_ans % MOD;
        }
        if (iStr[i] == 'm')
        {
            int tmp_ans = 0;
            for (int j = 0; j < i; j++)
            {
                if (iStr[j] == 'a')
                {
                    tmp_ans += iLength[j];
                }
            }
            iLength[i] = tmp_ans % MOD;
            iAns      += tmp_ans;
            iAns       = iAns % MOD;
        }
    }
}

void iShowResult()
{
    cout << iAns % MOD << endl;
}


int main()
{
    while (cin >> iStr)
    {
        iInit();

        iDynamicProgramming();

        iShowResult();

    }
}

// end
// ism
