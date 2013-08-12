#include <iostream>
using namespace std;

int main(){
    long long int a[35];
    a[0]=2;
    for(int i=1;i<35;i++){a[i]=3*a[i-1]+2;}
    int n;
    while(cin>>n){
        cout<<a[n-1]<<endl;
    }
    return 0;
}
//end
//ism