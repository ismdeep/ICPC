#include <iostream>
using namespace std;

int main(){
    int a[50];
    a[1]=1;a[2]=2;
    for(int i=3;i<50;i++){
        a[i]=a[i-1]+a[i-2];
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    }
    
    return 0;
}
//end
//ism
