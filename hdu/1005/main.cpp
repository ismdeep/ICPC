/*
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).

*/
#include <iostream>
using namespace std;

int main(){
    int a,b,n;
    int f1,f2;
    while(cin>>a>>b>>n&&a+b+n){
        int f[202];
        f[1]=1;
        f[2]=1;
        for(int i=3;i<202;i++){
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        }
        
        //mid = 100
        //starter = 101
        //1-100 101-200
        int flag;
        bool isok=false;
        for(flag=0;!isok;flag++){
            bool yes=true;
            for(int i=flag;i<100;i++){
                if(f[100+i-flag+1]!=f[i]){yes=false;}
            }
            if(yes){
                isok=true;
            }
        }
        
        flag--;
        
        if(n>=flag){
            n=(n-flag)%(100-flag+1)+flag;
        }
        
        cout<<f[n]<<endl;
    }
    return 0;
}
//end
//ism
