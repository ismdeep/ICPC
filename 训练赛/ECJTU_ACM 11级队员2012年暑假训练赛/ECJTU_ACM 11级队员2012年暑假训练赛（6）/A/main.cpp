#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //freopen("in.dat", "r", stdin);
    int iNum;
    int iCaseCount = 0;
    while (scanf("%d", &iNum) != EOF && iNum)
    {
        iCaseCount++;
        if (iNum%2 == 0)
        {
            printf("%d. even %d\n", iCaseCount, (iNum+1)/2);
        }
        else
        {
            printf("%d. odd %d\n", iCaseCount, iNum/2);
        }
    }
    return 0;
}

// end
// ism
