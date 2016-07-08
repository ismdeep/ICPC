#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int m,n;
bool map[100100];
struct node
{
	int x,step;
};
int bfs(int x)
{
	memset(map,0,sizeof(map));
	queue<node> q;
	node a,b,c;
	a.x=x;
	a.step=0;
	q.push(a);
	map[a.x]=1;
	while(!q.empty())
	{
		b=q.front ();
		q.pop();
		if(b.x==n)
		{
			return b.step;
		}
		if(b.x>=0&&b.x<100000&&!map[b.x])
		{
			c=b;
			c.x=b.x+1;
			c.step ++;
			q.push(c);
			map[c.x]=1;
		}
		if(b.x>=0&&b.x<100000&&!map[b.x])
		{
			c=b;
			c.x=b.x-1;
			c.step ++;
			q.push(c);
			map[c.x]=1;
		}
		if(b.x>=0&&b.x<100000&&!map[b.x])
		{
			c=b;
			c.x=2*b.x;
			c.step ++;
			q.push(c);
			map[c.x]=1;
		}
	}
	return -1;
}
int main()
{
	int ans;
	cin>>m>>n;
	ans=bfs(m);
	cout<<ans<<endl;
	return 0;
}

