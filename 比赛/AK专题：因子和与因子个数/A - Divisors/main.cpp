#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


#define MAXN 500

typedef unsigned long long int longint;



int i_gcd (int a, int b)
{
    int i_tmp;
    while (b)
    {
        i_tmp = a % b;
        a     = b;
        b     = i_tmp;
    }
    return a;
}

int i_min (int a, int b)
{
    return (a < b) ? a : b;
}

//////////////////////////////////////////////////
// data section
int divisor[MAXN+1];
int n, k;

void init_divisor ()
{
    for (int i = 0; i <= MAXN; i++)
    {
        divisor[i] = 1;
    }
}


void put_all_divisor (int iNum)
{
    for (int i = 2; i <= iNum; i++)
    {
        if (iNum % i == 0)
        {
            divisor[i]++;
            iNum  /= i;
        }
    }
}
void make_divisor ()
{
    k = i_min(k, n - k);
    int up[MAXN+1];
    int down[MAXN+1];
    int length = k;
    for (int i = 1; i <= k; i++)
    {
        up[i] = n - i + 1;
        down[i] = i;
    }
    int up_index;
    int down_index;
    for (up_index = 1; up_index <= length; up_index++)
    {
        for (down_index = 1; up[up_index] != 1 && down_index <= length; down_index++)
        {
            int i_gcd_value;
            i_gcd_value = i_gcd (up[up_index], down[down_index]);
            up[up_index] /= i_gcd_value;
            down[down_index] /= i_gcd_value;
        }
    }
    for (up_index = 1; up_index <= length; up_index++)
    {
        put_all_divisor (up[up_index]);
    }
}

longint get_count_sum ()
{
    longint sum = 1;
    for (int i = 0; i <= MAXN; i++)
    {
        sum *= divisor[i];
    }
    return sum;
}

int main ()
{
    while (scanf ("%d%d", &n, &k) != EOF)
    {
        init_divisor ();
        make_divisor ();
        cout << get_count_sum () << endl;
    }
    return 0;
}

// end
// namespace
// www.ism.name
