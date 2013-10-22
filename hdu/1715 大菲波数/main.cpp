#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 1010

class Number
{
public:
    int* a;
    int  iTop;
    void setSize(int n);
    void setValueSum(Number, Number);
    void setTopValue();
    void showValue();
};

void Number::setSize(int n)
{
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    iTop = n - 1;
}

void Number::setValueSum(Number num1, Number num2)
{
    for (int i = 0; i <= num2.iTop; i++)
    {
        a[i]  = num2.a[i];
    }
    for (int i = 0; i <= num1.iTop; i++)
    {
        a[i] += num1.a[i];
    }
    for (int i = 0; i <= iTop; i++)
    {
        a[i+1] += (a[i]/10);
        a[i]   %= 10;
    }
}

void Number::setTopValue()
{
    while (a[iTop] == 0)
    {
        iTop--;
    }
}

void Number::showValue()
{
    for (int i = iTop; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

Number iMap[MAXN];

void iMakeMap()
{
    iMap[1].setSize(1);
    iMap[1].a[0] = 1;
    iMap[2].setSize(1);
    iMap[2].a[0] = 1;

    for (int i = 3; i < MAXN; i++)
    {
        iMap[i].setSize(iMap[i-1].iTop+2);
        iMap[i].setValueSum(iMap[i-1], iMap[i-2]);
        iMap[i].setTopValue();
    }
}

int main()
{
    iMakeMap();
    int iT;
    scanf("%d", &iT);
    while (iT--)
    {
        int iIndex;
        scanf("%d", &iIndex);
        iMap[iIndex].showValue();
    }
    return 0;
}

// end
// ism
