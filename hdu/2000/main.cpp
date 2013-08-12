#include <iostream>

using namespace std;



void swap(char& ch1,char& ch2){

    char temp;

    temp=ch1;ch1=ch2;ch2=temp;

}



int main(){

    string str;

    while(cin>>str){

        if(str[0]>str[1]){swap(str[0],str[1]);}

        if(str[0]>str[2]){swap(str[0],str[2]);}

        if(str[1]>str[2]){swap(str[2],str[1]);}

        cout<<str[0]<<" "<<str[1]<<" "<<str[2]<<endl;

    }

    return 0;

}

//end;

//ism







/*qwe

asd

zxc 





Sample Output  e q w

a d s

c x z 





*/
