#include <stdio.h>

int t, m, n;
int dp[100][100];

int
main()
{
	int i, j, k;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &m, &n);
		for (j = 0; j <= m; j++)
		{
			for (k = 0; k <= n; k++)
			{
				dp[j][k] = 0;
			}
		}

		dp[0][0] = 1;
		for (j = 1; j <= m; j++)
		{
			for (k = 1; k <= n && k <= j; k++)
			{
				dp[j][k] = dp[j - 1][k - 1] + dp[j - k][k];
			}
		}

		int ans = 0;
		for (j = 1; j <= n; j++) ans += dp[m][j];

		printf("%d\n", ans);
	}

	return 0;
}
