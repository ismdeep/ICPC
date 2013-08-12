#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n&&n){
        int zhengshu=0,fushu=0,ling=0;
        while(n--){
            string temp;
            cin>>temp;
            if(temp=="0"){ling++;}
            else if    (temp[0]=='-'){fushu++;}
            else{zhengshu++;}
        }
        cout<<fushu<<" "<<ling<<" "<<zhengshu<<endl;
    }
    return 0;
}
//end
//ism
