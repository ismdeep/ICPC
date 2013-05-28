#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int sum=1;
        while(n--){
            int temp;
            cin>>temp;
            if(temp%2){sum=sum*temp;}
        }
        cout<<sum<<endl;
    }
    return 0;
}
//end
//ism
