#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 1000000

bool is_not_self_number[MAXN+1];
int d (int value)
{
    int sum = value;
    while (value)
    {
        sum += (value % 10);
        value /= 10;
    }
    return sum;
}


void make_is_not_self_number ()
{
    memset (is_not_self_number, 0, sizeof(is_not_self_number));
    for (int i = 1; i <= MAXN; i++)
    {
        if (false == is_not_self_number[i])
        {
            int tmp = 0;
            tmp = d (i);
            while (tmp <= MAXN && is_not_self_number[tmp] == false)
            {
                is_not_self_number[tmp] = true;
                tmp = d (tmp);
            }
        }
    }
}

int main ()
{
    make_is_not_self_number ();
    for (int i = 1; i <= MAXN; i++)
    {
        if (false == is_not_self_number[i])
        {
            printf ("%d\n", i);
        }
    }
    return 0;
}

