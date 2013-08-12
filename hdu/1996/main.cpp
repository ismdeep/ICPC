#include <iostream>
using namespace std;

long long int a[30];

void init(){
    a[0]=3;
    for(int i=1;i<30;i++){
        a[i]=a[i-1]*3;
    }
}


int main(){
    init();
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    }
    return 0;
}
