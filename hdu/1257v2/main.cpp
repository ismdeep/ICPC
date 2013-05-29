#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 200
#define MAX 30000

int main()
{

    //freopen("in.dat", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int iMap[MAXN] = {MAX};

        int i = 1;
        while (n--)
        {
            int num_tmp;
            scanf("%d", &num_tmp);
            int j;
            for (j = 0; j <= i; j++)
            {
                if (num_tmp <= iMap[j])
                {
                    iMap[j] = num_tmp;
                    break;
                }
            }
            if (j > i)
            {
                iMap[++i] = num_tmp;
            }
        }
        printf("%d\n", i);
    }
}

// end
// iCoding@CodeLab
