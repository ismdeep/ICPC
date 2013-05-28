#include <stdio.h>
#define PI 3.1415927

int main(){
    double a;
    while((scanf("%lf",&a))!=EOF){
        a=(double)4/3*PI*a*a*a;
        printf("%.3f\n",a);
    }
    return 0;
}
//end
//ism
