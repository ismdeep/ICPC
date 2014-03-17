/* 
 * Project Name : 10114
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Sat Feb 15 11:19:38 2014 
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

double dep[105];  
  
int main()  
{  
    int month, n, temp, i;  
    double downpay, monthpay, owe, r, car, nowdep;  
    while (scanf("%d%lf%lf%d", &month, &downpay, &owe, &n), month > 0)  
    {  
        memset(dep, 0, sizeof(dep));  
        while (n--)  
        {  
            scanf("%d%lf", &temp, &r);  
            dep[temp] = r;  
        }  
        car = owe + downpay;///加上首付款  
        nowdep = 0;  
        monthpay = owe / month;///月还款  
        for (i = 0;; ++i)  
        {  
            nowdep = (dep[i] ? dep[i] : nowdep);///当前折旧率  
            car *= 1 - nowdep;  
            if (owe < car) break;  
            owe -= monthpay;///更新所欠的钱  
        }  
        //printf("%d %s\n", i, (i > 1 ? "months" : "month"));///会WA  
        if (i == 1) puts("1 month");  
        else printf("%d months\n", i);  
    }  
    return 0;  
}  


// end 
// ismdeep
// xTarget
// 
