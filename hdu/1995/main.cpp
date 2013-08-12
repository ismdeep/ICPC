#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long int result=1;
        while(n!=k){
            result=result*2;
            k++;
        }
        cout<<result<<endl;
    }
    return 0;
}
//end
//ism
