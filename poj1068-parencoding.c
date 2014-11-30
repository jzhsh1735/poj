#include <stdio.h>

int t, n;
int p[20];

int
main()
{
	int i, j, k;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &p[i]);

		printf("1");
		for (i = 1; i < n; i++)
		{
			k = 1;
			for (j = i - 1; j >= 0; j--)
			{
				if (p[j + 1] - p[j] >= k) break;
				k += 1 - p[j + 1] + p[j];
			}
			printf(" %d", i - j);
		}
		printf("\n");
	}

	return 0;
}
