#include <stdio.h>
#include <stdlib.h>

int n, m;
int rock[100];
double rock_ori[100];
int dp[20000];

int
main()
{
	int i, j;
	double sum;

	while (scanf("%d", &n), n)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &rock_ori[i]);
			sum += rock_ori[i];
		}
		m = 0;
		for (i = 0; i < n; i++)
		{
			rock[i] = (int)(rock_ori[i] * 10000 / sum);
			m += rock[i];
		}
		for (i = 0; i < 20000; i++) dp[i] = -1;

		dp[0] = 0;
		for (i = n - 1; i >= 0; i--)
		{
			for (j = m; j >= rock[i]; j--)
			{
				if (dp[j - rock[i]] >= 0 && dp[j] < 0) dp[j] = i + 1;
			}
		}

		for (i = 5000; i >= 0; i--)
		{
			if (dp[i] >= 0) break;
		}
		while (i > 0)
		{
			if (i == rock[dp[i] - 1]) printf("%d\n", dp[i]);
			else printf("%d ", dp[i]);

			i = i - rock[dp[i] - 1];
		}
	}

	return 0;
}
