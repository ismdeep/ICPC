#include <iostream>
using namespace std;

long long int a[51];
void init(){
    a[0]=1;
    a[1]=2;
    for(int i=2;i<51;i++){a[i]=a[i-1]+a[i-2];}
}

int main(){
    int n;
    init();
    while(cin>>n){
        cout<<a[n-1]<<endl;
    }
    return 0;
}
//end
//ism
