/* 
 * Project Name : 1003
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sun Nov 18 23:01:47 2012 
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

#define MAX_SIZE 11000

void cal_LTC (int num)
{
	int flag = 0;
        for(int i = 1;i <= 100 && !flag;i++)
           for(int j = 1;j <= 100 && !flag;j ++)
               for(int k = 1;k <= 100 && !flag;k ++)
                   if(num == i*i+j*j+k*k)
                   {
                        printf("%d %d %d\n",i,j,k);
                        flag = 1;
                        break;
                   }
}

int main () 
{ 
	int value;
	while (cin >> value)
	{
		cal_LTC (value);
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

