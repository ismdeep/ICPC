#include <iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        int sum1=0,sum0=0;
        if(a>b){int temp=a;a=b;b=temp;}
        for(int i=a;i<=b;i++){
            if(i%2){sum1=sum1+(i*i*i);}
            else{sum0=sum0+(i*i);}
        }
        cout<<sum0<<" "<<sum1<<endl;
    }
    return 0;
}
//end
//ism
