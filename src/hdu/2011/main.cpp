//project name:2011
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double Cal(int);
        printf("%.2f\n",Cal(n));
    }
    return 0;
}
/////////////////////////////////////////////////
double Cal(int k){
    double result=0.0;
    for(int i=1;i<=k;i++){
        if(i%2)
        {
            result+=((double)1/i);
        }
        else
        {
            result+=(-(double)1/i);
        }
    }
    return result;
}
//end
//ism
