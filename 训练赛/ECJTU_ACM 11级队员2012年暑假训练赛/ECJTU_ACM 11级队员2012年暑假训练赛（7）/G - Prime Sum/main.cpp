#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 10010

bool prime[MAXN];

void iMakePrime()
{
    for (int i = 0; i < MAXN; i++)
    {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    int iCurrent = 2;
    for (iCurrent = 2; iCurrent * iCurrent < MAXN; iCurrent++)
    {
        if (prime[iCurrent] == true)
        {
            for (int j = iCurrent * iCurrent; j < MAXN; j += iCurrent)
            {
                prime[j] = false;
            }
        }
    }
}


void showmap()
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", iMap[i]);
    }
}

int main()
{
    iMakePrime();
    showmap();
    int iNum;
    while (scanf("%d", &iNum) && iNum != 0)
    {
        int iCount = 0;
        for (int i = 2; i * 2 < iNum; i++)
        {
            if (prime[i] == true && prime[iNum-i] && true)
            {
                iCount++;
            }
        }
        printf("%d\n", iCount);
    }
    return 0;
}

// end
// ism

