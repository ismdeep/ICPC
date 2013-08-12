//project name:2069 ( Coin Change )
//Author:键盘杀手
//Creat Date & Time:Tue Apr 17 09:48:20 2012
#include<iostream>
using namespace std;
int main()
{
    int i,j,k,t;
    int nums[251]={0},coins[5]={1,5,10,25,50};
    int ans[251][101]={0},ansTemp[251][101]={0};
    //…[i][j]表示i分钱由j个硬币组成的方案数
    ans[0][0] = 1;

    for(i=1;i<=5;i++)
    {
        for(j=0;j<=250;j++)
            for(k=0;k*coins[i-1]+j<=250;k++)
                for(t=0;t+k<101;t++)//总的硬币数要少于100
                    ansTemp[k*coins[i-1]+j][t+k] += ans[j][t];
        for(j=0;j<=250;j++)
            for(t=0;t<101;t++)
            {
                ans[j][t] = ansTemp[j][t];
                ansTemp[j][t]=0;
            }
    }

    for(i=1;i<=250;i++)
        for(j=1;j<=100;j++)
            nums[i] += ans[i][j];
    nums[0] = 1;
    while(cin>>i)
        cout<<nums[i]<<endl;
    return 0;
}
//end
//ism
/*
50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. 
*/
