#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define infinity    0x7f7f7f7f
#define minus_inf    0x80808080

#define MAXSIZE 1009

char model[MAXSIZE], pattn[MAXSIZE] ;
int next[MAXSIZE], len_1, len_2 ;

void getNext (char *ps, char *pe)
{
    int i, j ;
    i = 0 ;
    j = -1 ;
    next[0] = -1 ;

    while (i < pe - ps)
    {
        if (j == -1 || ps[i] == ps[j])
        {
            ++i ; ++j ;
            if (ps[i] != ps[j])
                next[i] = j ;
            else
                next[i] = next[j] ;
        }
        else
        {
            j = next[j] ;
        }
    }
}

int kmp (char *ms, char *me, char *ps, char *pe)
{
    int i, j, cnt ;
    i = j = cnt = 0 ;

    getNext (ps, pe) ;

    while (i < me - ms)
    {
        if (j == -1 || ms[i] == ps[j])
        {
            ++i ; ++j ;
        }
        else
        {
            j = next[j] ;
        }
        if (j == pe - ps)
        {
            ++cnt ;
            j = 0 ;
        }
    }

    return cnt ;
}

int main ()
{
    while (scanf ("%s", model), *model != '#')
    {
        scanf ("%s", pattn) ;
        getchar () ;
        printf ("%d\n", kmp (model, model +strlen (model), pattn, pattn + strlen (pattn))) ;
    }
    return 0 ;
}
