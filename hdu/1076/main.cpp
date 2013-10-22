#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int y,n;
        cin>>y>>n;
        y--;
        while(n){
            y++;
            if((y%4==0&&y%100!=0)||y%400==0){
                n--;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}
//end
//ism
