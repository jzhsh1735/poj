#include <stdio.h>

int weight[1000];
int value[1000];

int dp[70000];

int n, total;

int
max(int x, int y)
{
	return (x > y? x: y);
}

int
main()
{
	int i, j, flag, temp, cnt = 0;
	while (1)
	{
		n = 0;
		total = 0;
		flag = 0;
		for (i = 0; i < 6; i++)
		{
			scanf("%d", &temp);
			total += temp * (i + 1);
			if (temp > 0) flag = 1;

			for (j = 1; j <= temp; j *= 2)
			{
				weight[n] = value[n] = j * (i + 1);
				n++;
				temp -= j;
			}

			if (temp > 0)
			{
				weight[n] = value[n] = temp * (i + 1);
				n++;
			}
		}
		if (flag == 0) break;

		if (total % 2 == 1)
		{
			cnt++;
			printf("Collection #%d:\nCan't be divided.\n\n", cnt);
			continue;
		}
		total /= 2;

		for (i = 0; i <= total; i++) dp[i] = 0;
		for (i = 0; i < n; i++)
		{
			for (j = total; j >= weight[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}

		cnt++;
		if (dp[total] == total) printf("Collection #%d:\nCan be divided.\n\n", cnt);
		else printf("Collection #%d:\nCan't be divided.\n\n", cnt);
	}

	return 0;
}
