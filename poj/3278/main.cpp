#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX_SIZE 100000
bool visited[MAX_SIZE+1];

int n,k;
int cnt;
queue<int> q;

void bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		if (k == value)
		{
			break;
		}
		else if (-1 == value)
		{
			cnt++;
			q.push(-1);
		}
		else
		{
			// 一般的数字
			if (value-1>=0 && !visited[value-1])
			{
				q.push(value-1);
				visited[value-1] = true;
			}
			if (value+1<=MAX_SIZE && !visited[value+1])
			{
				q.push(value+1);
				visited[value+1] = true;
			}
			if (value*2<=MAX_SIZE && !visited[value*2])
			{
				q.push(value*2);
				visited[value*2] = true;
			}
		}
	}
	cout << cnt << endl;
}

int main ()
{
	while (cin >> n >> k)
	{
		memset(visited,0,sizeof(visited));
		while (!q.empty()){q.pop();}
		q.push(n);
		visited[n] = false;
		q.push(-1);
		bfs();
	}
	return 0;
}

