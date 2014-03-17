/* 
 * Project Name : 10137
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Mar 17 10:38:29 2014 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

#define MAXN 1010

int cmp(const void *_a, const void *_b)
{
    double *a = (double*)_a;
    double *b = (double*)_b;
    return *a - *b;
}

int main(void)
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int n, i, p;
    double aver, sum, exchange;
    double cost[MAXN];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)   break;
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%lf", &cost[i]);
            sum += cost[i];
        }
        aver = sum / n;
        aver = (int)(aver*100)/100.0;  /* floor the aver */ 
        exchange = 0;
        p = (int)((sum-aver*n)/0.01+0.1);
        qsort(cost, n, sizeof(double), cmp);    
        for (i = n-1; i >= n-p; i--)
            if (cost[i] > aver+0.01)
                exchange += cost[i]-(aver+0.01);
        for (i = n-p-1; i >= 0; i--)
            if (cost[i] > aver)
                exchange += cost[i]-aver;
        printf("$%.2lf\n", exchange);
    }
    return 0;
}
// end 
// ismdeep
// xTarget
// 
