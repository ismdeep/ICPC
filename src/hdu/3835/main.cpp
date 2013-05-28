#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int countFun(int);
        cout<<countFun(n)<<endl;
    }
    return 0;
}
/////////////////////////////////////////////////////
int countFun(int k){
    int count=0;
    int i=0;
    while(i*i<=k){
        int j;
        j=k-i*i;
        j=sqrt(j);
        if(i*i+j*j==k){
            if(i==0||j==0){
                count+=2;
            }
            else{
                count+=4;
            }
        }
        i++;
    }
    
    return count;
}
//end
//ism
