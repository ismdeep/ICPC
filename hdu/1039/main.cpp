#include <iostream>
using namespace std;

int main(){
    string str;
    while(cin>>str&&str!="end"){
        bool judge(string);
        if(judge(str)){
            cout<<"<"<<str<<"> is acceptable."<<endl;
        }
        else{
            cout<<"<"<<str<<"> is not acceptable."<<endl;
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////
bool judge(string s){
    bool yes=true;
    
    //判断是否有元音字母
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            count++;
        }
    }
    if(!count){
        yes=false;
    }
    
    
    //判断“不能为三个连续元音，不能为三个连续辅音”
    int count_vowel,count_consonant;
    count_vowel=0;count_consonant=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            count_vowel++;
            count_consonant=0;
        }
        else{
            count_consonant++;
            count_vowel=0;
        }
        if(count_vowel>=3||count_consonant>=3){
            yes=false;
            break;
        }
    }
    
    //判断“不能有连续相同字母”
    char pre=s[0];
    for(int i=1;s[i]!='\0';i++){
        if(s[i]==pre){
            yes=false;
            if(pre=='0'||pre=='e'){
                yes=true;
            }
        }
        pre=s[i];
    }
    
    
    return yes;
}
//end
//ism
