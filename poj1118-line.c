#include <stdio.h>
#include <stdlib.h>

int n;
int x[1000], y[1000];

int
main()
{
	int i, j, k;

	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

		int max = -1;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				int temp = 0;
				for (k = j + 1; k < n; k++)
				{
					int a = (x[i] - x[j]) * (y[i] - y[k]);
					int b = (x[i] - x[k]) * (y[i] - y[j]);
					if (a == b) temp++;
				}
				if (max < 0 || temp + 2 > max) max = temp + 2;
			}
		}
		printf("%d\n", max);
	}

	return 0;
}
