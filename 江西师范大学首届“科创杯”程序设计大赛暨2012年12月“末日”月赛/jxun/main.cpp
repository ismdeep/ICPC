#include <iostream>
#include <string>   
#include <stdio.h>   
using namespace std;


#define MaxVertexNum 110
#define INF 0x3ffffff

int inquiry_count;

typedef struct  
{   
    char vertex[MaxVertexNum];   
    int edges[MaxVertexNum][MaxVertexNum];   
    int n,e;   
}MGraph;   
 
void CreateMGraph(MGraph &G)   
{   
    int i,j,k,p;   
    // cout<<"请输入顶点数和边数:";   
    cin>>G.n>>G.e >> inquiry_count;   
    // cout<<"请输入顶点元素:";   
    for (i=0;i<G.n;i++)   
    {   
        // cin>>G.vertex[i];   
		G.vertex[i] = i;
    }   
    for (i=0;i<G.n;i++)   
    {   
        for (j=0;j<G.n;j++)   
        {   
            G.edges[i][j]=INF;   
            if (i==j)   
            {   
                G.edges[i][j]=0;   
            }   
        }   
    }      
    for (k=0;k<G.e;k++)   
    {   
        // cout<<"请输入第"<<k+1<<"条弧头弧尾序号和相应的权值:";   
        cin>>i>>j>>p;   
        G.edges[i][j] = p;   
		G.edges[j][i] = p;
    }   
}   
void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n);
 
void Floyd(MGraph G)
{
	int A[MaxVertexNum][MaxVertexNum],path[MaxVertexNum][MaxVertexNum];
	int i,j,k;
	for (i=0;i<G.n;i++)
	{
		for (j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			path[i][j]=-1;
		}
	}
	for (k=0;k<G.n;k++)
	{
		for (i=0;i<G.n;i++)
		{
			for (j=0;j<G.n;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	Dispath(A,path,G.n);
}
 
void Ppath(int path[][MaxVertexNum],int i,int j)
{
	int k;
	k=path[i][j];
	if (k==-1)
	{
		return;
	}
	Ppath(path,i,k);
	printf("%d,",k);
	Ppath(path,k,j);
}
 
void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n)
{
	int i,j;
	while (inquiry_count--)
	{
		cin >> i >> j;
			if (A[i][j]==INF)
			{
				if (i!=j)
				{
					// printf("从%d到%d没有路径\n",i,j);
					cout << "-1" << endl;
				}
			}
			else
			{
				printf ("%d\n", A[i][j]);
				// printf("  从%d到%d=>路径长度:%d路径:",i,j,A[i][j]);
				// printf("%d,",i);
				// Ppath(path,i,j);
				// printf("%d\n",j);
			}
	}
}
 
int main()
{
	// freopen("input2.txt", "r", stdin);
	MGraph G;
	CreateMGraph(G);
	Floyd(G);
	return 0;
}


