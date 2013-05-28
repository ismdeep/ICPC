#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        double sum=0;
        double temp=n;
        //sum+=(temp*temp);
        while(m--){
            temp=sqrt(temp);
            sum+=(temp*temp);
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
//end
//ism
