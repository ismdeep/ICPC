#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int mod = 10007;

int Pow(int x,int y)  //求x^y
{
    if (y==1) return x%mod;
    if (y==0) return 1;
    int half =Pow(x,y/2);
    if (y&1) return half*half%mod*x%mod;
    return half*half%mod;
}

//2^1 + 2^2 + 2^3 = 2^1 + 2*(2^1+2^2) = (2^1 + 2*2^1)+2*2^2 k为奇数
//2^1 + 2^2 + 2^3 + 2^4 + 2^5 = 2^1 + 2^2 + 2^2*(2^1+2^2+2^3) = 2^1 + 2^2 +  2^2*(2^1+2^2) + 2^2*2^3 k为奇数
//2^1 + 2^2 + 2^3 + 2^4 = 2^1 + 2^2 + 2^2*(+2^1+2^2) k为偶数
int f(int a,int k) //求表达式的值
{
    if (k==1) return a%mod;
    int ccc=k/2;
    int half = f(a,ccc);
    if (k&1) //k为奇数 奇数不能整除2 所以奇数的二进制最后一位是1 和十进制能不能被10整除看最后一位是不是0一个道理
    {
        int ooo=Pow(a,ccc); //公因子
        return ((half*ooo%mod + half)%mod + ooo*ooo%mod*a%mod)%mod;
    }

    return (half*Pow(a,ccc)%mod + half)%mod; //Pow(a,ccc)为公因子
}

int main()
{
    int a,k;
    while (scanf("%d%d",&a,&k)!=EOF)
    {
        printf("%d\n",f(a,k));
    }
    return 0;
}
