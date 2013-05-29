#include <iostream>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        if(n>m){int temp=n;n=m;m=temp;}
        int count=0;
        for(int i=n;i<=m;i++){
            int a,b,c;
            a=i/100;
            b=i/10-a*10;
            c=i%10;
            //cout<<a<<b<<c<<endl;
            if(i==(a*a*a+b*b*b+c*c*c)){
                if(count!=0){cout<<" ";}
                cout<<i;
                count++;
            }
        }
        if(count==0){cout<<"no"<<endl;}
        else{cout<<endl;}
    }
    return 0;
}
//end
//ism
