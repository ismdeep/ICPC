#include <stdio.h>
#include <math.h>
int main()
{
	double dp[2001];
	int m, n, i;
	scanf("%d", &n);
	scanf("%d", &m);
	while(n != 0 && m != 0)
	{
		for(i = 0; i < m; i++)
			dp[i] = 0;
		dp[m] = pow(0.5, m);
		for(i = m+1; i <= n; i++)
			dp[i] = dp[i-1] + (1-dp[i-m-1])*pow(0.5, m+1);
		printf("%.2lf\n", dp[n]);
		scanf("%d", &n);
		scanf("%d", &m);
	}
	return 0;
}

