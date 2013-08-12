#include <stdio.h>
int main(){
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d, r, i;
while (scanf("%d/%d/%d", &y, &m, &d) == 3){
   a[2] = y%4==0&&y%100!=0 || y%400==0 ? 29 : 28;
   r = 0;
   for (i=1; i<m; ++i){
    r += a[i];
   }
   r += d;
   printf("%d\n", r);
}
return 0;
}
//end
//ism
