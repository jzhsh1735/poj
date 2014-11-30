#include <stdio.h>

int t, n;
int l[5000], w[5000];
int dp[5000];

int
max(int x, int y)
{
	return x > y? x: y;
}

int
main()
{
	int i, j;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d %d", &l[i], &w[i]);

		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (l[i] > l[j] || l[i] == l[j] && w[i] > w[j])
				{
					int temp;
					temp = l[i]; l[i] = l[j]; l[j] = temp;
					temp = w[i]; w[i] = w[j]; w[j] = temp;
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			dp[i] = 1;
			for (j = 0; j < i; j++)
			{
				if (l[i] > l[j] && w[i] < w[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		int ans = 0;
		for (i = 0; i < n; i++) ans = max(ans, dp[i]);

		printf("%d\n", ans);
	}

	return 0;
}
