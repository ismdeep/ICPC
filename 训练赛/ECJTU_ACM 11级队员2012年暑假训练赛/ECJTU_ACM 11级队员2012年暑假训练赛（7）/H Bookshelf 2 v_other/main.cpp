#include <iostream>
#include <stdio.h>
using namespace std;

#define INT_MAX 2 << 10

int iMap[21],n,iBookshelf,iMin,iTmp;

void iTry(int k)
{
    if(k>n)return;
    if(iTmp>=iBookshelf&&iTmp-iBookshelf>=iMin)return;

    iTmp+=iMap[k];
    if(iTmp>=iBookshelf)
    {
      if(iTmp-iBookshelf<iMin)
        iMin=iTmp-iBookshelf;
    }
    else
    {
      iTry(k+1);
    }
    iTmp-=iMap[k];

    iTry(k+1);
}

int main()
{
    //freopen("in.dat", "r", stdin);
    int i;
    scanf("%d%d",&n,&iBookshelf);
    for(i=1;i<=n;i++)
      scanf("%d",&iMap[i]);

    iMin=INT_MAX;
    iTmp=0;
    iTry(1);
    printf("%d\n",iMin);

    return 0;
}

// end
// ism

