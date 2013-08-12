#include "stdio.h"

int Runnian(int y)
{
    if((y%4==0 && y%100!=0) || y%400==0)
        return 1;
    return 0;
}

int main()
{
    int year1,month1,day1,num,a,year2,i,year3;
       scanf("%d\n",&a);
       while(a--)
       {   num=0;
        scanf("%d-%d-%d",&year1,&month1,&day1)!=EOF;
        year2=year1+18;
        if(Runnian(year1) && !Runnian(year2) && ((month1==2)&&(day1==29)))
                 num=-1;
        else
        {
            for(i=1;i<=18;i++)
            {   
                year2=year1+1;
                if((Runnian(year1) && month1<=2) || (Runnian(year2) && month1>2))
                    num+=366;
                else
                    num=num+365;
                year1++;
            }
        }
        printf("%d\n",num);
       }
       return 0;
}
//end
//ism
