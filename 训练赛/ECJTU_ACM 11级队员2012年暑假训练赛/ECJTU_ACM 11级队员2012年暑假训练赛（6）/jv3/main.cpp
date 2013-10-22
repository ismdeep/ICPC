#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (3000 + 100)

int iFlag[MAXN], iNum[MAXN];
typedef long long int longint;


void iFac(int n) {
     memset(iFlag, 0, sizeof(iFlag));
     memset(iNum,  0, sizeof(iNum));
     int i, j, k;
     longint f;
     int iResult = 0;
     for(i = 1; i <= n; ++i)
         scanf("%d", &iNum[i]);
     for(k = 2; k <= n; ++k) {
         f = abs(iNum[k] - iNum[k - 1]);       //不是 abs(abs(iNum[k]) - abs(iNum[k - 1]))题意理解错误啊！！！！
         if(f < MAXN)
             iFlag[f] = f;
     }
     for(j = 1; j < n; ++j)
         if(!iFlag[j]) {
             iResult = 1;
             break;
         }
     if(iResult)
         printf("Not jolly\n");
     else
         printf("Jolly\n");
 }

int main() {
     int n;
     while(scanf("%d", &n) != EOF)
     {
         iFac(n);
     }
     return 0;
}


// end
// ism
