#include <stdio.h>

int prime[5000];
int flag[5000];
int n, c, cnt;

int
main()
{
	int i, j;

	for (i = 0; i <= 1000; i++) flag[i] = 0;
	prime[0] = 1;
	cnt = 1;
	for (i = 2; i <= 1000; i++)
	{
		if (flag[i] == 0)
		{
			prime[cnt] = i;
			cnt++;
			for (j = 2; i * j <= 1000; j++) flag[i * j] = 1;
		}
	}

	while (scanf("%d %d", &n, &c) != EOF)
	{
		for (i = 0; i < cnt && prime[i] <= n; i++);

		printf("%d %d:", n, c);
		if (i % 2 == 0)
		{
			if (2 * c > i) c = i / 2;
			for (j = i / 2 - c; j < i / 2 + c; j++) printf(" %d", prime[j]);
		}
		else
		{
			if (2 * c - 1 > i) c = i / 2 + 1;
			for (j = i / 2 - c + 1; j < i / 2 + c; j++) printf(" %d", prime[j]);
		}
		printf("\n\n");
	}

	return 0;
}
