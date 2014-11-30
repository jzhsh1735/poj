#include <stdio.h>

int flag[10000];
int sum[10000];
int num;

int n;

int
main()
{
	int i, j;

	for (i = 0; i < 10000; i++) flag[i] = 0;
	sum[0] = 0;
	num = 1;
	for (i = 2; i < 10000; i++)
	{
		if (flag[i] == 0)
		{
			for (j = 2; i * j < 10000; j++) flag[i * j] = 1;

			sum[num] = sum[num - 1] + i;
			num++;
		}
	}

	while (scanf("%d", &n), n)
	{
		int ans = 0;
		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (sum[j] - sum[i] == n) ans++;
				if (sum[j] - sum[i] > n) break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
