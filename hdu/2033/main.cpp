#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int h1,m1,s1;
        int h2,m2,s2;
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        s1+=s2;
        m1+=m2;
        h1+=h2;
        m1+=(s1/60);s1=s1%60;
        h1+=(m1/60);m1=m1%60;
        
        cout<<h1<<" "<<m1<<" "<<s1<<endl;
    }
    return 0;
}
//end
//ism
