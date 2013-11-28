#include <iostream>
using namespace std;

int main(){
    long long int a,b;
    while(cin>>a>>b){
        long long int countLength(long long int);
        int flag=false;
        if(a>b){long long int temp=a;a=b;b=temp;flag=true;}
        long long int max=countLength(a);
        for(long long int i=a+1;i<=b;i++){
            long long int temp=countLength(i);
            if(max<temp){max=temp;}
        }
        if(flag){long long int temp=a;a=b;b=temp;}
        cout<<a<<" "<<b<<" "<<max<<endl;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////
long long int countLength(long long int k){
    long long int count=1;
    while(k!=1){
        //cout<<k<<" ";
        if(k%2==1){
            k=k*3+1;
        }
        else{
            k=k/2;
        }
        count++;
    }
    //cout<<"1  @@"<<count<<endl;
    return count;
}
//end
//ism
