#include <stdio.h>

int n;
int dp[100];

int
main()
{
	int i;

	for (i = 0; i < 100; i++) dp[i] = 0;
	dp[0] = 1;
	dp[2] = 3;
	for (i = 4; i < 100; i += 2) dp[i] = 4 * dp[i - 2] - dp[i - 4];

	while (scanf("%d", &n), n != -1)
	{
		printf("%d\n", dp[n]);
	}

	return 0;
}
