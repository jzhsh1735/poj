#include <stdio.h>

int n;
int num[100];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i, j;

	while (scanf("%d", &num[n = 0]), num[0] != -1)
	{
		n++;
		while (scanf("%d", &num[n]), num[n] != 0) n++;
		qsort(num, n, sizeof(int), compare);

		int ans = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (2 * num[i] == num[j]) ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
