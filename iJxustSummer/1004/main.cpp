#include <iostream>
#include <fstream>
#include <stdio.h>

namespace ismdebug
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
};

//using ismdebug::cin;
using std::cin;
using std::cout;
using std::endl;
/* 前面的命名空间之类的你就别管了 */
/***********************************************************************************/
#define iMAXN 10000200

int iMapCount[iMAXN];

void iMakeMapCount()/*这个是一个简单的打表，里面计算的结果是每一个数对应的因子的个数*/
{
    for (int i = 0; i < iMAXN; i++)
    {
        iMapCount[i] = 0;/*初始置为0，因为后面是从1开始的，如果解决浪费时间的话，可以置为1，后面就从2，开始。*/
    }

    for (int i = 1; i*2 <= iMAXN; i++)/*打表核心代码段，当i = n的时候，1*n,2*n,3*n,4*n……都是n的倍数，那么n都是他们的因子
    那么就继续往后找，只要一直在所求范围里面就够。注意，看到后面的 j+=i了吧。那个很重要的。
    */
    {
        for (int j = i; j <= iMAXN; j += i)
        {
            iMapCount[j]++;/*表示找到一个倍数，那么就++咯。*/
        }
    }
}

void iScanner() /*为什么叫做scanner呢？因为这里是整理，找到之前出现的因子最多的数。*/
{
    int iFlag = 1;
    int iMaxCount = iMapCount[iFlag];

    for (int i = 2; i < iMAXN; i++)
    {
        if (iMapCount[i] > iMaxCount) /*找到了存在因为更多的数了，然后替换*/
        {
            iFlag = i;
            iMaxCount = iMapCount[i];
            iMapCount[i] = i;
        }
        else/*悲剧，没有找到啊，那么就用之前最大的来替换他咯，因为是表示这个以及这个之前出现的因子数最多的那个数*/
        {
            iMapCount[i] = iFlag;
        }
    }
}

void iOutputTest() /* 测试输出 iMapCount[] 里面的数值的，后面屏蔽掉了。*/
{
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " " << iMapCount[i] << endl;
    }
}

int main()
{
    iMakeMapCount(); /* 第一便打表 */
    iScanner(); /*打表完之后进行整理，我称之扫描*/
    //iOutputTest();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        /*打表完成之后就爽了，接下来就输入则输出就是了。同学说iScanner函数可以不用的，但是想过没有，输入数据是很多组，，5000啊，
        所以我还是先打表吧。然后scanner、一遍吧。
        */
        int iNum;
        scanf("%d", &iNum);
        printf("%d\n", iMapCount[iNum]);
    }
    return 0;
}

// end
// ism
