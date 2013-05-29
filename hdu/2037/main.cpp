//认为这是一个贪心算法的问题。
/*
对所有的时间段差值由小到大排序。接下来便是按照一定的顺序放进队列中。看是否有冲突，没有冲入则放进去。有冲突则丢弃。
*/
#include <iostream>
using namespace std;

class Node{
public:
int begin;
int end;
int time;
void getTime(){time=end-begin;}
};

int main(){
    int n;
    while(cin>>n&&n){
        Node *a=new Node[n];
        for(int i=0;i<n;i++){
            cin>>a[i].begin>>a[i].end;
            a[i].getTime();
        }
        
        //排序 
        for(int i=0;i<n;i++){
            int flag=i;
            for(int j=i+1;j<n;j++){
                if(a[j].time<a[flag].time){flag=j;}
            }
            Node temp;
            temp=a[i];a[i]=a[flag];a[flag]=temp;
        }
        /* 
        for(int i=0;i<n;i++){
            cout<<a[i].begin<<" "<<a[i].end
        }
         */
        
        Node *map=new Node[n];
        int top=-1;
        map[0]=a[0];
        top=0;
        for(int i=1;i<n;i++){
            bool yes=true;
            for(int j=0;yes&&j<=top;j++){
                if(a[i].begin>=map[j].end||a[i].end<=map[j].begin){}
                else{yes=false;}
            }
            if(yes){
                //加入 
                top++;
                map[top]=a[i];
            }
        }
        cout<<top+1<<endl;
    }
    return 0;
}
//end
//ism
