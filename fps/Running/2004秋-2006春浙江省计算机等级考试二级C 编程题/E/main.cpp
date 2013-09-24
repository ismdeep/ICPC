/*
 * Project     : E
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 15:10:19 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

typedef long long int longint;

int main()
{
	int n,j,k,t,x,max;
	int a[512][512];
	while(scanf("%d",&n),!(n>=1&&n<=6));
	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
			scanf("%d",&a[j][k]);
	max=a[0][0];t=0;x=0;
	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
			if(fabs(a[j][k]>max))
			{
				max=a[j][k];
				t=j;x=k;
			}
	printf("%d %d %d",a[t][x],t+1,x+1);
	return 0;
}



// end 
// iCoding@CodeLab
//

