#include <stdio.h>

int main()
{
    int hour, min, sec;
    int t;
    int tmp;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &hour, &min, &sec);
        scanf("%d", &tmp);
        hour += tmp;
        scanf("%d", &tmp);
        min  += tmp;
        scanf("%d", &tmp);
        sec  += tmp;

        min += (sec / 60);
        sec %= 60;

        hour += (min / 60);
        min %= 60;

        printf("%d %d %d\n", hour, min, sec);
    }
    return 0;
}

