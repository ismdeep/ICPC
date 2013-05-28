#include <iostream>
using namespace std;

int CStringToInt(string str){
    int intReturn;
    if(str=="one"){intReturn=1;}
    if(str=="two"){intReturn=2;}
    if(str=="three"){intReturn=3;}
    if(str=="four"){intReturn=4;}
    if(str=="five"){intReturn=5;}
    if(str=="six"){intReturn=6;}
    if(str=="seven"){intReturn=7;}
    if(str=="eight"){intReturn=8;}
    if(str=="nine"){intReturn=9;}
    if(str=="zero"){intReturn=0;}
    return intReturn;
}

int main(){
    string str;
    while(cin>>str){
        int a=0,b=0;
        a=CStringToInt(str);
        cin>>str;
        while(str!="+"){
            a=a*10+(CStringToInt(str));
            cin>>str;
        }
        
        cin>>str;
        while(str!="="){
            b=b*10+(CStringToInt(str));
            cin>>str;
        }
        
        a=a+b;
        if(a==0){
            return 0;
        }
        cout<<a<<endl;
        
    }
    return 0;
}
//end
//ism
