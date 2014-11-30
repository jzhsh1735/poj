#include <stdio.h>

int c, n;
int num[1000];
int sum, cnt;

int
main()
{
	int i;

	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			sum += num[i];
		}
		
		cnt = 0;
		for (i = 0; i < n; i++)
		{
			if (num[i] * n > sum) cnt++;
		}

		printf("%.3f%%\n", (double)cnt / n * 100);
	}

	return 0;
}
