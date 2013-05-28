#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<iomanip>
#include<set>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<string>
using namespace std;

#define N 111

int a[N],b[N];
int c[N*N];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,m;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
	    cin >> a[i];
	}
	cin>>m;
	for (int i = 0; i < m; i++)
	{
	    cin >> b[i];
	}
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < m; j++)
	    {
	        if (b[j] % a[i] == 0)
	        {
	            c[b[j]/a[i]]++;
	        }
	    }
	}
	bool found = false;
	for (int i = N - 1; !found && i >= 0; i--)
	{
	    if (c[i])
	    {
	        cout << c[i] << endl;
	        found = true;
	    }
	}
	return 0;
}

