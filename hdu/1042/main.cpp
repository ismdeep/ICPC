#include <iostream>
using namespace std;
void ism(){cout<<"ism"<<endl;}
int a[10000];

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<10000;i++){
            a[i]=0;
        }
        a[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                a[j]=a[j]*i;
            }
            for(int j=0;j<n-1;j++){
                a[j+1]=a[j+1]+(a[j]/10000);
                a[j]=a[j]%10000;
            }
        }
        
        //output
        int flag=9999;
        for(;a[flag]==0;flag--){}
        
        cout<<a[flag];
        for(int i=flag-1;i>=0;i--){
            if(a[i]<10){cout<<"000";}
            else if(a[i]<100){cout<<"00";}
            else if(a[i]<1000){cout<<"0";}
            
            cout<<a[i];
        }
        
        cout<<endl;
        
    }
    return 0;
}
//end
//ism
