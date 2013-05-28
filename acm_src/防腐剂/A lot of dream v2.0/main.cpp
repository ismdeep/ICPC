#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 10000007

const int index_d = 0;
const int index_r = 1;
const int index_e = 2;
const int index_a = 3;
const int index_m = 4;


typedef unsigned long long int longint;


const string dream = "dream";
longint iAns[5];

string iStr;

void iInit()
{
    for (int i = 0; i < 5; i++)
    {
        iAns[i] = 0;
    }
}

void iDynamicProgramming()
{
    int iTop = iStr.length() - 1;

    for (int i = 0; i <= iTop; i++)
    {
        if (iStr[i] == dream[index_d])
        {
            iAns[index_d]++;
        }
        if (iStr[i] == dream[index_r])
        {
            iAns[index_r] += iAns[index_d];
        }
        if (iStr[i] == dream[index_e])
        {
            iAns[index_e] += iAns[index_r];
        }
        if (iStr[i] == dream[index_a])
        {
            iAns[index_a] += iAns[index_e];
        }
        if (iStr[i] == dream[index_m])
        {
            iAns[index_m] += iAns[index_a];
        }

        // clear it by % MOD
        for (int index = 0; index < 5; index++)
        {
            iAns[index] %= MOD;
        }
    }

    printf("%d\n", (int)iAns[index_m]);
}

int main()
{
    char str_tmp[100010];
    while (scanf("%s", str_tmp) != EOF)
    {
        iStr = str_tmp;
        iInit();
        iDynamicProgramming();
    }
}

// end
// ism
