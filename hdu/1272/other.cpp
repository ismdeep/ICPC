#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *link;
struct node{
    int v;
    link next;
};

typedef struct graph *Graph;
struct graph{
    int V, E;
    link *adj;
};

struct Edge{ int v, w; };

Graph G;
const int maxv = 100000+5;
const int maxe = 100000+5;
bool used[maxv];
Edge Ev[maxe];
int queue[maxv], fromnode[maxv];

int cmp(const void *m, const void *n)
{
    if( (*(Edge*)m).v==(*(Edge*)n).v )
        return (*(Edge*)m).w - (*(Edge*)n).w;
    return (*(Edge*)m).v - (*(Edge*)n).v;
}

link NEW(int v, link next)
{
    link x = (link)malloc(sizeof *x);
    x->v = v; x->next = next;
    return x;
}

void GRAPHinit(Graph &G, int V)
{
    int i;
    G = (Graph)malloc(sizeof *G);
    G->adj = (link*)malloc((V+1)*sizeof(link));
    G->V = V; G->E = 0;
    for (i = 1; i<= V; i++) G->adj[i] = NULL;
}

void GRAPHinsertE(Graph G, Edge e)
{
        G->adj[e.v] = NEW(e.w, G->adj[e.v]);
        G->adj[e.w] = NEW(e.v, G->adj[e.w]);
        G->E++;
}

bool traverse(int nu)
{
    int begin, end, cur;
    begin = end = 0;
    queue[end++] = nu;
    fromnode[nu] = -1;
    used[nu] = true;

    while( begin<end )
    {
        cur = queue[begin++];
        link te = G->adj[cur];
        for( ; te; te = te->next )
        {
            if(used[te->v]&&te->v!=fromnode[cur]) return false;
            if(!used[te->v])
            {
                used[te->v] = true;
                fromnode[te->v] = cur;
                queue[end++] = te->v;
            }
        }
    }
    return true;
}

int main()
{
    int maxNo, v1, v2, en, i;
    Edge e;
    while( scanf("%d%d", &v1, &v2)&&!(v1==-1&&v2==-1) )
    {
        if( v1==0 && v2==0 )
        {
            puts("Yes");
            continue;
        }
        en = 0;
        if( v1>v2 )
            Ev[en].v = v2, Ev[en++].w = v1;
        else
            Ev[en].v = v1, Ev[en++].w = v2;
        maxNo = (v1>v2) ? v1 : v2;
        //if( v1==v2 ) en--;

        while( scanf("%d%d", &v1, &v2)&&!(v1==0&&v2==0) )
        {
            if( v1>v2 )
                Ev[en].v = v2, Ev[en++].w = v1;
            else
                Ev[en].v = v1, Ev[en++].w = v2;

            //if( v1==v2 ) en--;

            if( maxNo<v1 ) maxNo = v1;
            if( maxNo<v2 ) maxNo = v2;
        }

        qsort(Ev, en, sizeof(Ev[0]), cmp);
        //for(i=0; i<en-1; i++)
        //    if( Ev[i].v==Ev[i+1].v && Ev[i].w==Ev[i+1].w ) break;
        //if( i<en-1 ) puts("No");
        //else
        {
            GRAPHinit(G, maxNo);
            for(i=0; i<en; i++)
            {
                e.v = Ev[i].v, e.w = Ev[i].w;
                GRAPHinsertE(G, e);
            }

            memset(used, 0, sizeof(bool)*(maxNo+1));

            if( !traverse(maxNo) ) puts("No");
            else
            {
                for(i=0; i<en; i++)
                    if( !used[Ev[i].v] || !used[Ev[i].w] ) break;
                if( i<en ) puts("No");
                else puts("Yes");
            }    
        }
    }
    return 0;
}


