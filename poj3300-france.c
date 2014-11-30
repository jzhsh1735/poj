#include <stdio.h>
#include <stdlib.h>

int f, r;
int ft[10], rt[10];
double ratio[100];
double ans;

int
compare(const void *x, const void *y)
{
	if (*(double *)x > *(double *)y) return 1;
	else return -1;
}

int
main()
{
	int i, j;

	while (scanf("%d", &f), f)
	{
		scanf("%d", &r);
		for (i = 0; i < f; i++) scanf("%d", &ft[i]);
		for (i = 0; i < r; i++) scanf("%d", &rt[i]);

		for (i = 0; i < f; i++)
		{
			for (j = 0; j < r; j++)
			{
				ratio[i * r + j] = (double)rt[j] / ft[i];
			}
		}
		qsort(ratio, f * r, sizeof(double), compare);
		ans = 0;
		for (i = 0; i < f * r - 1; i++)
		{
			if (ratio[i + 1] / ratio[i] > ans) ans = ratio[i + 1] / ratio[i];
		}
		printf("%.2f\n", ans);
	}

	return 0;
}
