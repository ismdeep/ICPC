#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){count++;}
        }
        count%=2;
        cout<<count<<endl;
    }
    return 0;
}
//end
//ism
