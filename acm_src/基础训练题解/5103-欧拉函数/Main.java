import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main（String args[]）
    {
        Scanner cin=new Scanner（System.in）;
        int i，j，num=0，t;
        BigInteger ans = null;
        long[] prime=new long[30000];
        boolean[] flag=new boolean[200000];
        BigInteger n，temp;
        for（i=0;i<200000;i++）
            flag[i]=false;
        for(i=2;i<200000;i++)
        {
            if（!flag[i]）
            {
                prime[num]=i;
                num++;
                for（j=i+i;j<200000;j=j+i）
                    flag[j]=true;
            }
        }
        t=cin.nextInt();
        for（j=1;j<=t;j++）
        {
            temp=BigInteger.ONE;
            n=cin.nextBigInteger（）;
            for（i=0;i<num;i++）
            {
                temp=temp.multiply（BigInteger.valueOf（prime[i]））;
                if（temp.compareTo（n）<=0）
                    ans=temp;
                else
                    break;
            }
            System.out.println（ans）;
        }
    }
}


