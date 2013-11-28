#include <iostream>
using namespace std;

typedef long long int LL;


int score[1100];
int n;
LL me;
int me_score;

int main ()
{
	while (cin >> me)
	{
		LL a,b;
		n = 0;
		while (cin >> a >> b, a + b)
		{
			score[n] = b;
			n++;
			if (a == me)
			{
				me_score = b;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (me_score < score[i])
			{
				cnt++;
			}
		}
		cout << cnt+1 << endl;
	}
	return 0;
}


