#include <stdio.h>
#include <stdlib.h>

int m, n;
int level[1000];
int water;

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i, temp, cnt = 0;
	double ans;

	//while (scanf("%d %d", &m, &n), m && n)
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (m == 0 && n == 0) break;

		for (i = 0; i < m * n; i++) scanf("%d", &level[i]);
		scanf("%d", &water);

		qsort(level, m * n, sizeof(int), compare);
		temp = 0;
		for (i = 0; i < m * n - 1; i++)
		{
			if (temp + 100 * (i + 1) * (level[i + 1] - level[i]) < water) temp += 100 * (i + 1) * (level[i + 1] - level[i]);
			else break;
		}
		ans = level[i] + (double)(water - temp) / (100 * (i + 1));
		if (water > temp) i++;

		cnt++;
		printf("Region %d\n", cnt);
		printf("Water level is %.2f meters.\n", ans);
		printf("%.2f percent of the region is under water.\n\n", (double)i / (m * n) * 100);
	}

	return 0;
}
