#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;


int main()
{
    double num;
    while ( cin >> num )
    {
        printf("%.2f\n", fabs(num));
    }
    return 0;
}
