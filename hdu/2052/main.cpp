#include <iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        char map[80][80];
        for(int i=0;i<80;i++){for(int j=0;j<80;j++){map[i][j]=32;}}
        
        map[0][0]='+';
        map[0][a+1]='+';
        map[b+1][0]='+';
        map[b+1][a+1]='+';
        
        for(int i=1;i<=a;i++){map[0][i]='-';map[b+1][i]='-';}
        for(int i=1;i<=b;i++){map[i][0]='|';map[i][a+1]='|';}
        
        for(int i=0;i<=b+1;i++){for(int j=0;j<=a+1;j++){cout<<map[i][j];}cout<<endl;}
        
        cout<<endl;
    }
    return 0;
}
//end
//ism
