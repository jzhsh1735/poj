#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e8
#define ZERO 1e-8

int n;
int x[1000], y[1000];
double k[1000];

int
compare(const void *x, const void *y)
{
	return *(double *)x > *(double *)y? 1: -1;
}

int
main()
{
	int i, j;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

		int max = -1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (x[i] == x[j]) k[j] = INF;
				else k[j] = (double)(y[i] - y[j]) / (x[i] - x[j]);
			}
			qsort(k, n, sizeof(double), compare);

			int temp = 1;
			for (j = 0; j < n - 1; j++)
			{
				if (j == 0 || fabs(k[j] - k[j - 1]) < ZERO) temp++;
				else
				{
					if (temp > max) max = temp;
					temp = 2;
	 			}
			}
			if (temp > max) max = temp;
		}
		printf("%d\n", max);
	}

	return 0;
}
