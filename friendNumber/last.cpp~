#include <iostream>
using namespace std;

class FriendNumber
{
public:
    int x;
    int y;
};


FriendNumber num[100];
int top;


void init(){
    
    num[0].x=220;num[0].y=284;
    num[1].x=1184;num[1].y=1210;
    num[2].x=2620;num[2].y=2924;
    num[3].x=5020;num[3].y=5564;
    num[4].x=6232;num[4].y=6368;
    num[5].x=10744;num[5].y=10856;
    num[6].x=12285;num[6].y=14595;
    num[7].x=17296;num[7].y=18416;
    num[8].x=63020;num[8].y=76084;
    num[9].x=66928;num[9].y=66992;
    num[10].x=67095;num[10].y=71145;
    num[11].x=69615;num[11].y=87633;
    num[12].x=79750;num[12].y=88730;
    num[13].x=100485;num[13].y=124155;
    num[14].x=122265;num[14].y=139815;
    num[15].x=122368;num[15].y=123152;
    num[16].x=141664;num[16].y=153176;
    num[17].x=142310;num[17].y=168730;
    num[18].x=171856;num[18].y=176336;
    num[19].x=176272;num[19].y=180848;
    num[20].x=196724;num[20].y=202444;
    num[21].x=203432;num[21].y=185368;
    num[22].x=280540;num[22].y=365084;
    num[23].x=308620;num[23].y=389924;
    num[24].x=319550;num[24].y=430402;
    num[25].x=356408;num[25].y=399592;
    num[26].x=437456;num[26].y=455344;
    num[27].x=469028;num[27].y=486178;
    num[28].x=514736;num[28].y=503056;
    num[29].x=522405;num[29].y=525915;
    num[30].x=600392;num[30].y=669688;
    num[31].x=624184;num[31].y=691256;
    num[32].x=643336;num[32].y=652664;
    num[33].x=667964;num[33].y=783556;
    num[34].x=686072;num[34].y=609928;
    num[35].x=726104;num[35].y=796696;
    num[36].x=802725;num[36].y=863835;
    num[37].x=898216;num[37].y=980984;
    num[38].x=947835;num[38].y=1125765;
    num[39].x=1043096;num[39].y=998104;
    num[40].x=1077890;num[40].y=1099390;
    num[41].x=1154450;num[41].y=1189150;
    num[42].x=1156870;num[42].y=1292570;
    
    top = 42;
}

int main()
{
    int a,b;
    init();
    while( cin >> a >> b )
    {
        if( a > b )
        {
            int temp;
            temp = a;
            a    = b;
            b    = temp;
        }
        
        int count = 0;
        for(int i = 0; i <= top; i++)
        {
            if(num[i].x >= a && num[i].y <= b)
            {
                count++;
            }
        }
        
        cout << count << endl;
        
    }
    
    return 0;
}

// end
// ism


