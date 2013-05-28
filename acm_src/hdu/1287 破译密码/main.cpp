#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int n,i;
    int a[1000];
    char ch;

    while(cin>>n)
    {
      for(i=0;i<n;i++)
          scanf("%d",&a[i]);

      int count=0;
      char xx;
      for(ch='A'; ch<='Z'; ++ch)
      {
          count=0;
          for(i=0; i<n; i++)
          {
              xx=a[i]^ch;
             if(xx<='Z'&& xx>='A') count++;
          }
          if(count==n)  break;

      }

      for(i=0;i<n;i++)
      {
          printf("%c",a[i]^ch);
      }
      printf("\n");
    }

    return 0;
}

