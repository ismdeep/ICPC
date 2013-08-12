#include <stdio.h>

int main(){
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    
    double sum=2.5;
    int fac=2;
    for(int i=3;i<=9;i++){
        fac=fac*i;
        sum=sum+((double)1/fac);
        printf("%d %.9f\n",i,sum);
    }
    
    return 0;
}
//end
//ism
