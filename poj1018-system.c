#include <stdio.h>

int t, n;
int m[100];
int b[100][100];
int p[100][100];
int maxb, minb;
int sump;
double result;

int
main()
{
	int i, j, k, l;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		maxb = minb = -1;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &m[j]);
			for (k = 0; k < m[j]; k++)
			{
				scanf("%d %d", &b[j][k], &p[j][k]);
				if (maxb < 0 || b[j][k] > maxb) maxb = b[j][k];
				if (minb < 0 || b[j][k] < minb) minb = b[j][k];
			}
		}

		result = -1;
		for (j = minb; j <= maxb; j++)
		{
			sump = 0;
			for (k = 0; k < n; k++)
			{
				int minp = -1;
				for (l = 0; l < m[k]; l++)
				{
					if (b[k][l] >= j && (minp < 0 || minp > p[k][l])) minp = p[k][l];
				}
				if (minp > 0) sump += minp;
				else
				{
					sump = -1;
					break;
				}
			}
			if (sump > 0 && (double)j / sump > result) result = (double)j / sump;
		}

		printf("%.3f\n", result);
	}

	return 0;
}
