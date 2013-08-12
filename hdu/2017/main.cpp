#include <iostream>
#include <string>
using namespace std;

    int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int top=0;
        int count=0;
        while(str[top]!='\0'){
            if(str[top]>='0'&&str[top]<='9'){
                count++;
            }
            top++;
        }
        cout<<count<<endl;
    }
    return 0;
}
//end
//ism
